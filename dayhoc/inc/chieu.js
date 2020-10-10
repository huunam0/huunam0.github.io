var stt=0;
function bandau()
{
	if (stt<batdau) 
	{
		next();
		setTimeout(bandau,1000);
	}
}
function next()
{
	stt++;
	var strid="#tt"+stt;
	if ($(strid).length>0) 
	{
		$(strid).show();
		if ($(strid).attr("wait"))
		{
			//$("#debug").append( $(strid).attr("wait") + "<br/>");
			var w = parseInt($(strid).attr("wait"));
			$("#debug").append("Tu chuyen sau " + w + "ms<br/>");
			setTimeout(next,w);
		}
		
	}
}
function thu()
{
	alert(stt);
}