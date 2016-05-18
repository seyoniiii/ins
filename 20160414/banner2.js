function scroll(len) {
  var m1  = "1.1 이것은 JavaScript를 이용하여 <DIV> 블록에 Banner1을 보여줍니다. ";
  var m2  = "2.1 이것은 <DIV> 블록에 Banner2를 보여줍니다.";

  var msg=m1+m2;
  var out = " ";
  var c   = 1;

  if (len > 100) {
    len--;
    var cmd="scroll(" + len + ")";
    timerTwo=window.setTimeout(cmd, 100);
  }
  else if (len <= 100 && len > 0) {
    for (c=0 ; c < len ; c++) {
          out+=" ";
    }
    out+=msg;
    len--;
    var cmd="scroll(" + len + ")";
    document.getElementById("bann").innerHTML = out;
    timerTwo=window.setTimeout(cmd, 100);
  }
  else if (len <= 0) {
    if (-len < msg.length) {
       out+=msg.substring(-len, msg.length);
       len--;
       var cmd="scroll(" + len + ")";
       document.getElementById("bann").innerHTML=out;
       timerTwo=window.setTimeout(cmd, 100);
    }
    else {
       document.getElementById("bann").innerHTML=" ";
       timerTwo=window.setTimeout("scroll(100)", 75);
    }
  }
}
