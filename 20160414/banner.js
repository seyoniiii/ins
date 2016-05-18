function scroll(len) {
  var m1  = "1.1 �̰��� JavaScript�� �̿��Ͽ� â �ϴܿ� Banner1�� �����ݴϴ�. ";
  var m2  = "2.1 �̰��� â �ϴܿ� Banner2�� �����ݴϴ�.";

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
    window.status=out;
    timerTwo=window.setTimeout(cmd, 100);
  }
  else if (len <= 0) {
    if (-len < msg.length) {
       out+=msg.substring(-len, msg.length);
       len--;
       var cmd="scroll(" + len + ")";
       window.status=out;
       timerTwo=window.setTimeout(cmd, 100);
    }
    else {
       window.status=" ";
       timerTwo=window.setTimeout("scroll(100)", 75);
    }
  }
}
