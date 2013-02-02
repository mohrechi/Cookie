/**
 * 获取URL中的query string，通过名称查找。
 */
function getQueryString(name){
     var result = location.search.match(new RegExp("[\?\&]" + name+ "=([^\&]+)","i"));
     if(result == null || result.length < 1) {
         return "";
     }
     return result[1];
}
