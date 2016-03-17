// note, io(<port>) will create a http server for you
var io,php,crud,appId,appSecret,mysqlInfo,concurrency,pageRank;

io = require('socket.io').listen(3000);
Promise = require('bluebird');
utilities = require('./src/utilities');
crud = require('./src/crud');
request = utilities.promisify(require('request'));
pageRank = utilities.promisify(require('pagerank'));
//pageRank = require('pagerank');
concurrency = 2;
appId = '842ab811f4';
appSecret = 'b5f8cac50c8947323099e028011357a6c96d5340';

mysqlInfo = {
    host     : '192.168.1.172',
    user     : 'root',
    password : '123@123',
    database : 'chiaki_sa'
};
crud.connect(mysqlInfo);
utilities.setSecurityData(appId,appSecret);

io.sockets.on('connection', function (socket) {
    var spidering,spideringInfo,dataInfo,listRank;

    socket.on('getpagerank',function(data){
        console.log(data);
        listRank = [];
        crud.getListLinkN(data.id).then(function(arrPages){
            return getPageRank(arrPages);
        }).then(function(){
            crud.multiUpdatePagesRank(listRank);
            io.emit('getpagerank',listRank);
        }).catch(function(err) {
             console.log('err getpagerank...');
        });
    })
    //them 1 link vao 1 page
    socket.on('addlink',function(data){
        console.log(data);
        var url,lm_link_json,addData;
        url = utilities.getUrl(data.urlCode.host,'addlink');
        lm_link_json = utilities.getLinkData(data.adsObj);
        addData = utilities.getSecurityData();
        addData.lm_page_code = data.urlCode.code;
        addData.lm_link_id = data.adsObj.id;
        addData.lm_link_json =JSON.stringify(lm_link_json);
        console.log(addData);
        utilities.postWordpress(url,addData,function(data){
            console.log(data);
        });
    });

    //add 1 ads vao nhieu page
    socket.on('multiaddlink',function(data){
        console.log(data);
        var addData = utilities.getSecurityData();
        url = utilities.getUrl(data.resourcesCode.host,'multiaddlink');
        addData.lm_pages_code = data.listUrlCode;
        addData.lm_link_id = data.adsObj.id;
        addData.lm_link_json = JSON.stringify(utilities.getLinkData(data.adsObj));
        utilities.postWordpress(url,addData);
    });
     //add nhieu ads vao nhieu page
    socket.on('multiaddlinkfromclipboard',function(listData){
        recursivePost(listData);    
    });

    function recursivePost(listData){
        setTimeout(function(){
            var data = listData.shift(); 
            var addData = utilities.getSecurityData();
            url = utilities.getUrl(data.resourcesCode.host,'multiaddlink');
            addData.lm_pages_code = data.listUrlCode;
            addData.lm_link_id = data.adsObj.id;
            addData.lm_link_json = JSON.stringify(utilities.getLinkData(data.adsObj));
            utilities.postWordpress(url,addData);
            if(listData.length > 0){
                recursivePost(listData);
            }
        }, 2000)
        
    }
    //add nhieu ads vao 1 page
    socket.on('multiaddads',function(data){
        console.log(data);
        var listAdsObj,newListObj,url,addData;
        newListObj = [];
        listAdsObj = data.listAdsObj;
        url = utilities.getUrl(data.urlCode.host,'multiaddads');
        addData = utilities.getSecurityData();
        addData.lm_page_code = data.urlCode.code;

        if(listAdsObj){
            for(var i = 0; i < listAdsObj.length;i++){
                newListObj.push(utilities.getLinkData(listAdsObj[i]));
            }
        }
        addData.list_ads = newListObj;
        utilities.postWordpress(url,addData);
    });

    //xoa 1 link (ads) trong 1 page
    socket.on('removelink',function(data){
        var url,deleteData;
        url = utilities.getUrl(data.urlCode.host,'removelink');
        deleteData = utilities.getSecurityData();
        deleteData.lm_page_code = data.urlCode.code;
        deleteData.lm_link_id = data.link_ads_id;
        utilities.postWordpress(url,deleteData);
    });
    //xoa tat ca link (ads) trong 1 page
    socket.on('removepage',function(data){
        var url,deleteData;
        url = utilities.getUrl(data.urlCode.host,'removepage');
        deleteData = utilities.getSecurityData();
        deleteData.lm_page_code = data.urlCode.code;
        utilities.postWordpress(url,deleteData);
    });
    //xoa het link (ads)  trong nhieu page
    socket.on('removeallpage',function(data){
        var url,deleteData;
        url = utilities.getUrl(data.resourcesCode.host,'removeallpage');
        deleteData = utilities.getSecurityData();
        deleteData.lm_pages_code = data.listUrlCode;
        utilities.postWordpress(url,deleteData);
    });
    //xoa 1 link (ads) trong nhieu page
    socket.on('multiremovelink',function(data){
        var url,deleteData,listUrlCode;
        console.log(data);
        url = utilities.getUrl(data.host,'multiremoveLink');
        deleteData = utilities.getSecurityData();
        deleteData.lm_pages_code = data.listUrlCode;
        deleteData.lm_link_id = data.adsId;
        console.log(deleteData);
        utilities.postWordpress(url,deleteData);
    });


    socket.on('updateconfig',function(data){
        var config =  JSON.stringify(data.config);
        var urlCode = data.urlCode;
        var url = utilities.getUrl(urlCode.host,'savedisplay');
        var addData = utilities.getSecurityData();
        addData.lm_json_display = config;
        utilities.postWordpress(url,addData);
    });

    socket.on('multiupdateconfig',function(data){
        var config =  JSON.stringify(data.config);
        var listWebsite = data.listWebsite;
        var addData = utilities.getSecurityData();
        if(listWebsite.length > 0){
            for(var i = 0; i < listWebsite.length;i++){
                var urlCode = listWebsite[i];
                url = utilities.getUrl(urlCode.host,'savedisplay');
                addData.lm_json_display = config;
                utilities.postWordpress(url,addData);
            }
        }
    });

    socket.on('getsource',function(data){
        var url = utilities.getUrl(data.host,'getsource');
        var postData = utilities.getSecurityData();
        console.log(url);
        console.log(postData);
        utilities.postWordpress(url,postData,function(err,response,body){
            console.log('getsource result');
            console.log(body);
            socket.emit('getsource',{content:body})
        });
    })

    socket.on('updatesource',function(data){
        var url = utilities.getUrl(data.host,'updatesource');
        var postData = utilities.getSecurityData();
        postData.content = data.content;
        utilities.postWordpress(url,postData,function(err,response,body){
           socket.emit('updatesource',{status:'ok'});
        });
    })

    socket.on('gethtaccess',function(data){
        var url = utilities.getUrl(data.host,'gethtaccess');
        var postData = utilities.getSecurityData();
        utilities.postWordpress(url,postData,function(err,response,body){
            socket.emit('gethtaccess',{content:body})
        });
    })

    socket.on('updatehtaccess',function(data){
        var url = utilities.getUrl(data.host,'updatehtaccess');
        var postData = utilities.getSecurityData();
        postData.content = data.content;
        utilities.postWordpress(url,postData,function(err,response,body){
           socket.emit('updatehtaccess',{status:'ok'});
        });
    })

    socket.on('crawl',function(data){
        console.log(data);
        if(data.link && data.deep){
            console.time('spider');
            crud.setInfoData(data);
            spidering = {};
            spideringInfo = [];
            dataInfo = data;
            spider(data.link,data.deep)
                .then(function() {
                    if(spideringInfo.length > 0){
                        crud.multiCreate(spideringInfo);
                    }
                    console.log('Complete' );
                    console.log(Object.keys(spidering).length);
                    var emitData = {
                        'link_id' : data.id,
                        'link' : data.link,
                        'linkn' : JSON.stringify(spidering)
                    };
                    socket.emit('crawl',emitData);
                    io.emit('endCrawl',emitData);
                    console.timeEnd('spider');
                })
                .catch(function(err) {
                    console.log(err);
                });
        }
    });

    socket.on('crawlGoogle',function(data){
        console.log(data);
        crud.setInfoData(data);
        crawlGoogle(data.link).then(function(){
            console.log('done');
             var emitData = {
                'link_id' : data.id,
                'link' : data.link,
                'linkn' : []
            };
            io.emit('endCrawl',emitData);
        });
    });


    function spiderLinks(currentUrl, pageInfo, nesting) {
        if(nesting === 0 || pageInfo.links.length == 0) {
            return Promise.resolve();
        }
        return Promise.map(pageInfo.links,function(link){
            return spider(link, nesting - 1);
        }, {concurrency:concurrency})
     
    
    }

    function getInfo(url){
        var param = {
            //time : milisecond
            uri: url ,
            headers: { 
                "User-Agent": "Mozilla/5.0 (X11; Linux i686) AppleWebKit/537.31 (KHTML, like Gecko) Chrome/26.0.1410.",
                "Cache-Control":"no-cache, no-store, must-revalidate"
            },
            maxRedirects : 3
        };
        return request(param)
            .then(function(results) {
                var body,pageInfo;
                console.log('Get Content : ' + url);
                body = results[1];
                pageInfo = utilities.getPageInfo(url, body);
                if(pageInfo.title){
                    spidering[url] = pageInfo.title;
                    spideringInfo.push({
                        'link' : url,
                        'title': pageInfo.title
                    });
                }else{
                    spideringInfo.push({
                        'link' : url
                    });
                }
                if(Object.keys(spideringInfo).length > 100){
                   crud.multiCreate(spideringInfo);
                   spideringInfo = [];
                }
                io.emit('onCrawl',{url:url,link_id:dataInfo.id,total:Object.keys(spidering).length});
                //save
                //crud.create(url,pageInfo.title);
                return pageInfo;
            })
    }

    function spider(url, nesting) {
        if(spidering[url]) {
            return Promise.resolve();
        }
        spidering[url] = true;
        //save
        return getInfo(url)
            .then(function(pageInfo) {
                return spiderLinks(url, pageInfo, nesting);
            })
            .catch(function(err) {
                console.log(err);
                return Promise.resolve();
            });
    }

     function getPageRank(arrPages){
        return Promise.map(arrPages,function(linkPage){
            return pageRank(linkPage).then(function(rank){
                listRank[linkPage] = rank;
            }).catch(function(err) {
                console.log('err pageRank link: '+ linkPage);
            });
        }, {concurrency:3})
    }

});


// var link = 'http://www.rockymountainsavings.com/category/forthehome/?paged=6';

// if((/\?/).test(link) && !(/\?(cat=|p=|m=)/).test(link)){
//     console.log('tim thay, khong cho qua');
//     return null;
//   }else{
//     console.log('cho qua')
//   }
// if((/\.(gif|jpg|jpeg|tiff|png|php)$/i).test(link)
//     || (/(redirect_to|=true)/i).test(link)
//     || (/(wp-login)/i).test(link)
//     || (/(\/go\/|\/browse\/|\/go-store\/)/).test(link)
//     || (/\?/).test(link) ){
//         console.log('block');

//     }
 // crud.setInfoData({
 //    link: 'http://couponcodezone.com/',
 //    id : 12
 // });
//  var paramsGoogleApi = {
//     q: 'site:chiaki.vn',
//     rsz:rszGoogleApi,
//     start:0,
//     v:'1.0'
// }
var allLink = [];
var allLinkDataCreate = [];
var allParams = [];
/*
responseData
responseDetails"
responseStatus
*/
function crawlGoogle(crawlUrl){
    for(var i = 0; i <= 60;i++){
        allParams.unshift({q: crawlUrl,start:i * 10});
    }
    return Promise.map(allParams,function(params){
        console.log(params);
        return request(utilities.buildGoogleWebParams(params)).then(function(data){
            var result = utilities.parsePageGoogle(crawlUrl, data[1]);
            console.log(result);
            if(result.length > 0){
                crud.multiCreate(result);
            }
        })
    }, {concurrency:1});
}
//crawlGoogle('hieuorion.vn');
 // var dataInfo = [
 //    {link: 'http://wordpress.net/2015/10/22/bai-viet-so-7/','title': 'demo1'},
 //    {link: 'http://wordpress.net/2015/10/22/bai-viet-so-8/','title': 'demo2'},
 //    {link: 'http://wordpress.net/2015/10/22/bai-viet-so-9/','title': 'demo3'},
 //    {link: 'http://wordpress.net/2015/10/22/bai-viet-so-10/','title': 'demo4'},
 //    {link: 'http://wordpress.net/2015/10/22/bai-viet-so-1/','title': 'demo5'},
 //    {link: 'http://wordpress.net/2015/10/14/hello-world/','title': 'demo6'}
 // ]
 // crud.multiCreate(dataInfo);
 // var dataInfo = { 
 //    'http://couponcodezone.com/': 'Promo Code November 2015: Find Coupons & Discount Codes',
 //  'http://couponcodezone.com/share-coupon/': 'Share Coupon | Coupon Code Zone',
 //  'http://couponcodezone.com/about/': 'About | Coupon Code Zone',
 //  'http://couponcodezone.com/stores/': 'Stores | Coupon Code Zone',
 //  'http://couponcodezone.com/u/register/': 'Register | Coupon Code Zone',
 //  'http://couponcodezone.com/blog/': 'Blog | Coupon Code Zone',
 //  'http://couponcodezone.com/categories/': 'Categories | Coupon Code Zone',
 //  'http://couponcodezone.com/u/login/': 'Login | Coupon Code Zone',
 //  'http://couponcodezone.com/feed/?post_type=coupon': 'Coupon Code Zone',
 //  'http://couponcodezone.com/u/get-password/': 'Retrieve your lost password for Coupon Code Zone',
 //  'http://couponcodezone.com/coupon-category/adult-book-clubs/': 'adult-book-clubs Promo Code November 2015: Find adult-book-clubs Coupons & Discount Codes',
 //  'http://couponcodezone.com/benefits-when-shopping-at-best-buy/': 'Benefits When Shopping at Best Buy | Coupon Code Zone',
 //  'http://couponcodezone.com/?s=Kmart': 'Kmart FREE Shipping Coupons: Get 20 OFF Toys & Mobile Coupons 2015',
 //  'http://couponcodezone.com/back-to-school-savings-on-amazon-com/': 'Back-to-school Savings on Amazon.com | Coupon Code Zone',
 //  'http://couponcodezone.com/category/couponing/': 'Couponing | Coupon Code Zone',
 //  'http://couponcodezone.com/save-money-with-abercrombie-and-fitch-coupons/': 'Save Money with Abercrombie and Fitch Coupons | Coupon Code Zone',
 //  'http://couponcodezone.com/?s=GoDaddy': 'GoDaddy Coupon Codes Renewal: Receive 30 OFF W/ Renewal Coupon 2015',
 //  'http://couponcodezone.com/stores/eden-fantasys/': 'Eden Fantasys Promo Code November 2015: Find Eden Fantasys Coupons & Discount Codes',
 //  'http://couponcodezone.com/?s=Kohls': 'Kohls MVC Free Shipping Code 2015 & Kohls Coupons 30% OFF',
 //  'http://couponcodezone.com/?s=Newegg': 'Newegg Shipping Promo Code: Receive Coupon Codes 10 OFF November 2015',
 //  'http://couponcodezone.com/stores/best-buy/': 'Best Buy Promo Codes 10 OFF: Grab Appliance Coupon, More Coupons 2015',
 //  'http://couponcodezone.com/coupon-category/accessories/': 'accessories Promo Code November 2015: Find accessories Coupons & Discount Codes',
 //  'http://couponcodezone.com/decorate-bed-room-with-warm-color-classic-style/': 'Decorate bed room with warm color classic style',
 //  'http://couponcodezone.com/category/back-to-school/': 'Back to School | Coupon Code Zone',
 //  'http://couponcodezone.com/author/lipero/': 'Author | lipero - Coupon Code Zone',
 //  'http://couponcodezone.com/category/fashion/': 'Fashion | Coupon Code Zone',
 //  'http://couponcodezone.com/stores/kohls/feed/': 'Coupon Code Zone » Kohls',
 //  'http://couponcodezone.com/cdn-cgi/l/email-protection': 'Email Protection | CloudFlare',
 //  'http://couponcodezone.com/stores/best-buy/feed/': 'Coupon Code Zone » Best Buy',
 //  'http://couponcodezone.com/back-to-school-savings-at-hollister/': 'Back-to-school Savings at Hollister | Coupon Code Zone',
 //  'http://couponcodezone.com/author/camhh/': 'Author | camhh - Coupon Code Zone' }
// var fruits = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100];
// var length = fruits.length;

// console.log(fruits);
// var str = 0;
// for (var i = 1; i <= 100; i++) {
//    str += ',' + i
// };
// console.log(str);
// var cheerio = require('cheerio');
//  var param = {
//             //time : milisecond
//             uri: 'http://wordpress.net/' ,
//             headers: { 
//                 "User-Agent": "Mozilla/5.0 (X11; Linux i686) AppleWebKit/537.31 (KHTML, like Gecko) Chrome/26.0.1410.",
//                 "Cache-Control":"no-cache, no-store, must-revalidate"
//             },
//             maxRedirects : 3
//         };
//         return request(param)
//             .then(function(results) {
//                 //save
//                return results[1];
//             }).then(function(body){
//                 var titleObj = cheerio.load(body)('title');
//                 console.log(titleObj.length);
//                 console.log(titleObj[0].children[0].data);
//                 // return [].slice.call(cheerio.load(body)('title'))
//                 // .map(function(element) {
//                 //    console.log(element.children[0].data);
//                 // })
//             })

// var arrPages = {
//   'http://couponcodezone.com/stores/': 0,
//   'http://couponcodezone.com/': 2,
//   'http://couponcodezone.com/share-coupon/': 0,
//   'http://couponcodezone.com/sitemap.xml': null,
//   'http://couponcodezone.com/privacy-policy/': 1,
//   'http://couponcodezone.com/terms-of-use/': 1,
//   'http://couponcodezone.com/about/': 1,
//   'http://couponcodezone.com/take-pleasure-in-dynamic-clothing-with-hollister-coupons/': 0,
//   'http://couponcodezone.com/baby-clothing-at-target/': 0,
//   'http://couponcodezone.com/save-money-with-abercrombie-and-fitch-coupons/': 0,
//   'http://couponcodezone.com/back-to-school-savings-on-amazon-com/': 0,
//   'http://couponcodezone.com/benefits-when-shopping-at-best-buy/': 0,
//   'http://couponcodezone.com/coupons/free-shipping-on-orders-over-59/': null,
//   'http://couponcodezone.com/coupons/up-to-60-off-on-sale-items-free-shipping/': null,
//   'http://couponcodezone.com/coupons/flat-rate-shipping-only-6-99-with-orders-under-59/': null,
//   'http://couponcodezone.com/coupons/10-off-orders-over-99-free-shipping/': null,
//   'http://couponcodezone.com/coupons/200-off-on-taylormade-aeroburner-free-shipping/': null,
//   'http://couponcodezone.com/coupons/10-worth-of-snacks-for-free-w-the-feed-promo-code/': null,
//   'http://couponcodezone.com/coupons/10-worth-of-product-for-free-every-25-orders/': null,
//   'http://couponcodezone.com/coupons/refer-a-friend-and-get-10-in-cash/': null,
//   'http://couponcodezone.com/coupons/free-shipping-on-orders-over-49/': null,
//   'http://couponcodezone.com/coupons/free-bonk-breaker-fuel-recover-kit-on-any-order/': null,
//   'http://couponcodezone.com/stores/bookbyte/': 0,
//   'http://couponcodezone.com/stores/famous-footwear/': 0,
//   'http://couponcodezone.com/stores/urban-outfitters/': 1,
//   'http://couponcodezone.com/stores/sears/': 0,
//   'http://couponcodezone.com/stores/zulily/': 1,
//   'http://couponcodezone.com/stores/6pm/': 1,
//   'http://couponcodezone.com/stores/target/': 0,
//   'http://couponcodezone.com/stores/zazzle/': 0,
//   'http://couponcodezone.com/stores/kohls/': 0,
//   'http://couponcodezone.com/stores/amazon-com/': 1,
//   'http://couponcodezone.com/coupon-category/hotels/': 1,
//   'http://couponcodezone.com/coupon-category/toys/': 1,
//   'http://couponcodezone.com/coupon-category/sporting-goods/': 0,
//   'http://couponcodezone.com/coupon-category/shoes/': 0,
//   'http://couponcodezone.com/coupon-category/photography-and-videography/': 1,
//   'http://couponcodezone.com/coupon-category/pets/': 1,
//   'http://couponcodezone.com/coupon-category/party-supplies/': 1,
//   'http://couponcodezone.com/coupon-category/office-supplies/': 0,
//   'http://couponcodezone.com/coupon-category/musical-instruments/': 1,
//   'http://couponcodezone.com/coupon-category/jewelry/': 1,
//   'http://couponcodezone.com/coupon-category/home-and-garden/': 1,
//   'http://couponcodezone.com/coupon-category/furniture/': 0,
//   'http://couponcodezone.com/coupon-category/food-drinks/': 1,
//   'http://couponcodezone.com/coupon-category/gifts-flowers/': 0,
//   'http://couponcodezone.com/coupon-category/automotive/': 0,
//   'http://couponcodezone.com/coupon-category/books/': 1,
//   'http://couponcodezone.com/coupon-category/beauty-fitness/': null,
//   'http://couponcodezone.com/coupon-category/babies-kids/': 0,
//   'http://couponcodezone.com/coupon-category/electronics/': 0,
//   'http://couponcodezone.com/coupon-category/accessories/': 0,
//   'http://couponcodezone.com/coupon-category/clothing-2/': 0,
//   'http://couponcodezone.com/add-comment/up-to-40-off-on-select-top-sellers-items/': null,
//   'http://couponcodezone.com/go/up-to-40-off-on-select-top-sellers-items/1241617': null,
//   'http://couponcodezone.com/stores/maker-shed/': null,
//   'http://couponcodezone.com/add-comment/fall-fashion-30-off-or-more-on-clothing-shoes-and-accessories/': null,
//   'http://couponcodezone.com/go/fall-fashion-30-off-or-more-on-clothing-shoes-and-accessories/1248455': null,
//   'http://couponcodezone.com/stores/aliexpress/': null,
//   'http://couponcodezone.com/add-comment/75-off-clearance-sale/': null,
//   'http://couponcodezone.com/go/75-off-clearance-sale/1248188': null,
//   'http://couponcodezone.com/stores/macys/': null,
//   'http://couponcodezone.com/add-comment/free-shipping-on-orders-over-50-free-returns/': null,
//   'http://couponcodezone.com/go/free-shipping-on-orders-over-50-free-returns/729': null,
//   'http://couponcodezone.com/stores/old-navy/': null,
//   'http://couponcodezone.com/add-comment/15-off-with-the-purchase-of-2-on-same-items/': null,
//   'http://couponcodezone.com/go/15-off-with-the-purchase-of-2-on-same-items/1242664': null,
//   'http://couponcodezone.com/stores/temp-tations/': null,
//   'http://couponcodezone.com/add-comment/clearance-sale-70-off-on-6pm-clearance-items-free-shipping/': null,
//   'http://couponcodezone.com/go/clearance-sale-70-off-on-6pm-clearance-items-free-shipping/1497': null,
//   'http://couponcodezone.com/add-comment/50-off-on-holiday-spending-with-malta-discount-card/': null,
//   'http://couponcodezone.com/go/50-off-on-holiday-spending-with-malta-discount-card/1226081': null,
//   'http://couponcodezone.com/stores/viator/': 0,
//   'http://couponcodezone.com/add-comment/free-shipping-on-orders-of-35/': null,
//   'http://couponcodezone.com/go/free-shipping-on-orders-of-35/1226729': null,
//   'http://couponcodezone.com/add-comment/15-off-on-orders-over-100-free-shipping/': null,
//   'http://couponcodezone.com/go/15-off-on-orders-over-100-free-shipping/1236263': null,
//   'http://couponcodezone.com/add-comment/deal-frenzy-70-off-tech-fashion-home-and-more/': null,
//   'http://couponcodezone.com/go/deal-frenzy-70-off-tech-fashion-home-and-more/1248295': null,
//   'http://couponcodezone.com/stores/ebay/': null,
//   'http://couponcodezone.com/?s=GoDaddy': 0,
//   'http://couponcodezone.com/?s=Kmart': 1,
//   'http://couponcodezone.com/?s=Kohls': 0,
//   'http://couponcodezone.com/?s=Newegg': 0,
//   'http://couponcodezone.com/feed/?post_type=coupon': null,
//   'http://couponcodezone.com/u/login/': 0,
//   'http://couponcodezone.com/u/register/': 0,
//   'http://couponcodezone.com/blog/': 0,
//   'http://couponcodezone.com/categories/': 0
// };

