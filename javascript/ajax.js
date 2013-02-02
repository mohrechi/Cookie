/**
 * 获取ajax操作的基本对象。
 */
function getXMLHttp() {
    if(window.XMLHttpRequest) {
        return new XMLHttpRequest();
    } else {
        return new ActiveXObject("Microsoft.XMLHTTP");
    }
}

/**
 * 使用GET方式的示例。
 */
function getExample() {
    var xmlhttp = getXMLHttp();
    xmlhttp.onreadystatechange = function() {
        if(xmlhttp.readyState == 4 && xmlhttp.status == 200) {
            alert(xmlhttp.responseText);
    }
    xmlhttp.open("GET", "target.php?param=123");
    xmlhttp.send();
}    

/**
 * 使用POST方式的示例
 */
function postExample() {
    var xmlhttp = getXMLHttp();
    xmlhttp.onreadystatechange = function() {
        if(xmlhttp.readyState == 4 && xmlhttp.status == 200) {
            alert(xmlhttp.responseText);
        }
    }
    xmlhttp.open("POST", "target.php");
    xmlhttp.setRequestHeader("Content-Type","application/x-www-form-urlencoded");
    xmlhttp.send("param=123");
}
