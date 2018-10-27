/////////////////////////////////////////////// check ///////////////////////////////////////////////
var checkIsplay = function (){
	if($('#button_play').hasClass('pause')){
		return false;
	} else {
		return true;
	}
}
var checkIsfullScreen = function (){
	if($('#full_sc_btn').hasClass('small')){
		return false;
	} else {
		return true;
	}
}
/////////////////////////////////////////////// set ///////////////////////////////////////////////
function setPlay(isplay){
	if (isplay)
		$('#button_play').removeClass('pause');
	else
		$('#button_play').addClass('pause');
}
function setFullScreen(isFull){
	if (isplay)
		$('#full_sc_btn').removeClass('small');
	else
		$('#full_sc_btn').addClass('small');
}

function setTimeprocessbar(percent){
	$('.control-player-line-play').css('width',percent+'%');
}

function setBufferprocessbar(percent){
	$('.control-player-line-load').css('width',percent+'%');
}

function setDuration(time){
	$('#duration').text(time);
}

function setDurationCurrent(time){
	$('#current-time').text(time);
}

function setHiddenLoading(hide){
	if (hide){
		$('#loading-bg').css('display', 'none');
	} else {
		$('#loading-bg').css('display', 'block');
	}
}

function setShowControls(){
	$('.control-player-wrapper').css('bottom',0);
 	runAutohide(5);
}

function setHiddenSlideDuration(isHide){
	if (isHide){
		$('.control-player-line-load').css('width',100+'%');
		$('.control-player-line-play').css('width',100+'%');
	} else {
		$('.control-player-line-load').css('width',1+'%');
		$('.control-player-line-play').css('width',0+'%');
	}
}

function sendloadAds(){
	var kTestAppAdTagUrl = 'https://pubads.g.doubleclick.net/gampad/ads?sz=640x480&iu=/124319096/external/single_ad_samples&ciu_szs=300x250&impl=s&gdfp_req=1&env=vp&output=vast&unviewed_position_start=1&cust_params=deployment%3Ddevsite%26sample_ct%3Dlinear&correlator=';
	sendActiontoNative({'method':'setAttribute','value':['doubleClickRequestAds',kTestAppAdTagUrl]});
}

var getVideoHolderHeight = function(){
	return $('.abc1').height();
}

/////////////////////////////////////////////// native comunicate ///////////////////////////////////////////////
function sendActiontoNative(content){
	window.webkit.messageHandlers.sylvanasBridge.postMessage(content);
}
/////////////////////////////////////////////// timer auto hide ///////////////////////////////////////////////
var timeoutHideControlPlayer;
function runAutohide(duration){
	
	clearTimeout(timeoutHideControlPlayer);
	timeoutHideControlPlayer=setTimeout(function(){
										$('.control-player-wrapper').css('bottom','-55px');
										}, duration * 1000);
}

jQuery(document).ready(function($) {
					   setHiddenLoading(true);
					   setPlay(true);
					   var x = getVideoHolderHeight();
					   $('#button_play').click(function(event) {
											   /* Act on the event */
											   $(this).toggleClass('pause');
											   var stateCurrent = checkIsplay();
											   if (stateCurrent){
											   //goi pause
											   sendActiontoNative({'method':'Pause','value':'none'});
											   } else {
											   //goi play
											   sendActiontoNative({'method':'Play','value':'none'});
											   }
											   
											   });
					   
					   $('#full_sc_btn').click(function(event) {
											   /* Act on the event */
											   $(this).toggleClass('small');
											   if (checkIsfullScreen()){
											   //goi pause
											   sendActiontoNative({'method':'Minimize','value':'none'});
											   } else {
											   //goi play
											   sendActiontoNative({'method':'Maximize','value':'none'});
											   }
											   });
					   
					   var x = 1;
					   $('.volum-group .mute').click(function(event) {
													 x++;
													 $(this).removeClass('action1 action2 action3')
													 if(x == 2) {
													 $(this).addClass('action2');
													 }
													 if(x == 3) {
													 $(this).addClass('action3');
													 }
													 if(x == 4) {
													 $(this).addClass('action1');
													 x = 1;
													 }
													 });
					   
					   $('.setting-group .setting').click(function(event) {
														  /* Act on the event */
														  $(this).next('.setting-list').toggle();
														  });
					   
					   $('.setting-list li').click(function(event) {
												   /* Act on the event */
												   $('.setting-list li').removeClass('active');
												   $(this).addClass('active');
												   $(this).parent().toggle();
												   });
					   
					   $('.share-group').click(function(event) {
											   /* Act on the event */
											   $(this).toggleClass('active');
											   $('.frame-share').toggle();
											   });
					   
					   $('.frame-share-facebook').click(function(event) {
														/* Act on the event */
														$('.form-input').val('https://www.facebook.com/truyentranhtuan/?hc_ref=NEWSFEED&fref=nf');
														$('.frame-share-ul li').removeClass('active');
														$(this).addClass('active');
														});
					   
					   $('.frame-share-link').click(function(event) {
													/* Act on the event */
													$('.form-input').val('http://dantri.com.vn/the-gioi/tong-thong-phap-benh-vuc-vo-truoc-mieng-luoi-the-gian-20170511155023341.htm');
													$('.frame-share-ul li').removeClass('active');
													$(this).addClass('active');
													});
					   
					   $('.frame-share-embed').click(function(event) {
													 /* Act on the event */
													 $('.form-input').val('<iframe width=460 height=307 src=http://vcplayer.vcmedia.vn/1.1/?_site=dantri&vid=dantri/756edd3768/2017/05/11/dam-cuoi-tong-thong-phap-1494492123531.MP4&autoplay=false&_info=57f0e58ff4ab4ec49c6acc8041069507&_listsuggest=http://mcm.dantri.com.vn/video/zone-6/suggest-videos.htm&urlParent=http://dantri.com.vn/the-gioi/tong-thong-phap-benh-vuc-vo-truoc-mieng-luoi-the-gian-20170511155023341.htm data-type="video-iframe" frameborder="0" scrolling="no" allowfullscreen="" webkitallowfullscreen="" mozallowfullscreen="" oallowfullscreen="" msallowfullscreen=""></iframe>');
													 $('.frame-share-ul li').removeClass('active');
													 $(this).addClass('active');
													 });
					   });
$('.abc2').click(function(event){
				 setShowControls();
				 });

$('.time-group').click(function(event){
					   sendloadAds();
					   });

var sendPlayState = function(isplay){
	sendPlayStatetoNative(isplay);
}

