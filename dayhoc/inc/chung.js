$(document).ready(function(){
	$.urlParam = function(name){
		var results = new RegExp('[\?&]' + name + '=([^&#]*)').exec(window.location.href);
		if (results) return results[1];
		return  "";
	}
	//
	var norun=$.urlParam("norun")+"";
	var lophoc=$.urlParam("lop")+"";
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

		$("img.bamthay").click(function(){ //bấm vào thay hình khác
			var src = $(this).attr("src");
			$(this).attr("src",src.replace( ".", "x."));
		});
		$("img.bamthay").dblclick(function(){ //click luon goi truoc dblclick
			var src = $(this).attr("src");
			$(this).attr("src",src.replace( "x.", "."));
			alert(src.replace( "x.", "."));
		});
		if (lophoc == "") lophoc = prompt("Nhập tên người học","11Tin");
		$("body").append("<div><br/><br/><br/><br/><br/><br/>THNam-"+lophoc+"-"+currentDate()+"</div>");
		$("a").attr('href', function(i, h) {
			return h + (h.indexOf('?') != -1 ? "&" : "?") + "lop="+lophoc;
		});
	}
	else 
	{
		$(".landau").hide(); //ẩn bớt chi tiết, dùng để xem lại
	}
	
});
$(document).keydown(function(e) {
	if(e.keyCode == 37 || e.keyCode == 38) { // left or up : hide previoux element
		//alert("left");
		$(".mucan:visible:last").fadeOut(1000);
		$(".anngay:hidden:last").show();
	}
	else if(e.keyCode == 39 || e.keyCode == 40) { // right or down : show next element
		//alert("right");
		$(".mucan:hidden:first").show().effect('highlight',{},5000*(e.keyCode - 38));;
		$(".anngay:visible:first").hide();
		//$(".mucan:hidden:first").fadeIn(2000);
	}
	else {
		//alert(e.keyCode);
	}
});

function currentDate()
{
	var d= new Date();
	return d.getDate()+"/"+d.getMonth()+"/"+d.getFullYear();
}