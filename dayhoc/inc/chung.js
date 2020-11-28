$(document).ready(function(){
	$.urlParam = function(name){
		var results = new RegExp('[\?&]' + name + '=([^&#]*)').exec(window.location.href);
		if (results) return results[1];
		return  "";
	}
	//
	var norun=$.urlParam("norun")+"";
	var lophoc=$.urlParam("lop")+"";
	var boqua=parseInt("0"+$.urlParam("next"));
	//alert(norun.length);
	if (norun.length==0 || norun== "0")
	{
		$(".mucan").hide();
		$(".bamhien").each(function(){
			$(this).attr("gtri",$(this).text());
		});
		$(".bamhien").html("???");
		$(".bamhien").click(function(){ //bấm vào mới hiện nội dung
			$(this).html($(this).attr("gtri"));
			//$(this).removeClass("bamhien");
		});
		$(".bammat").click(function(){ //bấm vào là mất
			$(this).hide();
		});	
		$(".click2blue").click(function(){ //bấm vào là mất
			$(this).css("color","blue");
		});
		$(".click2red").click(function(){ //bấm vào là mất
			$(this).css("color","red");
		});
		$("img.bamthay").click(function(){ //bấm vào thay hình khác
			var src = $(this).attr("src");
			$(this).attr("src",src.replace( ".", "x."));
		});
		$("img.bamthay").dblclick(function(){ //click luon goi truoc dblclick
			var src = $(this).attr("src");
			$(this).attr("src",src.replace( "x.", "."));
			alert(src.replace( "x.", "."));
		});
		//alert(boqua);
		while (boqua>0) {
			hientiep();
			boqua-=1;
		}
		//alert(boqua);
		if (lophoc == "") lophoc = prompt("Nhập tên người học","11Tin");
		$("body").append("<div contenteditable='true'><br/><br/><br/><br/><br/><br/>THNam - "+lophoc+" - "+currentDate()+"</div>");
		$("a").attr('href', function(i, h) {
			return h + (h.indexOf('?') != -1 ? "&" : "?") + "lop="+lophoc;
		});
		//alert(currentDate());
	}
	else 
	{
		$(".landau").hide(); //ẩn bớt chi tiết, dùng để xem lại
	}
	
});
function hientiep(ekeyCode=0)
{
	if (ekeyCode>0)
		$(".mucan:hidden:first").show().effect('highlight',{},2000*(ekeyCode - 38));
	else
		$(".mucan:hidden:first").show();
	$(".anngay:visible:first").hide();
}
function hoanmot()
{
	$(".mucan:visible:last").hide();
	$(".anngay:hidden:last").show();
}
$(document).keydown(function(e) {
	if(e.keyCode == 37 || e.keyCode == 38) { // left or up : hide previoux element
		//alert("left");
		hoanmot();
	}
	else if(e.keyCode == 39 || e.keyCode == 40) { // right or down : show next element
		//alert("right");
		hientiep(e.keyCode);
		//$(".mucan:hidden:first").fadeIn(2000);
	}
	else {
		//alert(e.keyCode);
	}
});

function currentDate()
{
	var d= new Date();
	return d.getDate()+"/"+(d.getMonth()+1)+"/"+d.getFullYear();
}