console.log(noX("xaxxabx"));

function noX(str) {
    if(str.length == 0) return "";
    return str[0] == "x" ? noX(str.substr(1, str.length)) : str[0] + noX(str.substr(1, str.length));
}
