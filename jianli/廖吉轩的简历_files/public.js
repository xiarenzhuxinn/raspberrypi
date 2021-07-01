//网站公告
// var notifyTipTimer = setInterval(function(){
//   var $headFixed = document.querySelector('.head_fixed');
//   if(document.querySelector('#resume_pc')){
//     clearInterval(notifyTipTimer);
//   }else if($headFixed){
//     clearInterval(notifyTipTimer);
//     var $headFixedFirst= $headFixed.childNodes[0];
//     var $notifyTip = document.createElement("div");
//     $notifyTip.className='notify_tip';
//     $notifyTip.innerHTML = '<p class="page_w"><b>公告：</b>本站将于2021年04月10日 00:00~00:10 进行升级维护，期间可能会造成短暂的网络卡顿，给各位带来不便敬请谅解！<p>';
//     $headFixed.insertBefore($notifyTip,$headFixedFirst);
//   }
// },500);


//悬浮广告
// if(!/(\/cv\/)|(\/zp\/)|(\/order\/)/.test(location.href)){
//   window.onload = function(){
//     var qmad_box  = document.createElement('div');
//     qmad_box.className = 'qmad_box qmad_base';
//     qmad_box.style.width = '120px';
//     qmad_box.style.backgroundColor = 'rgba(19,216,167,.86)';
//     qmad_box.innerHTML = '<a href="/zp/storicard.html" target="_blank"><b>招聘</b><p style="font-size:14px;">iOS开发工程师<br>20K~40K<br>上海 · 张江<br>外企金融</p></a><div class="close el-dialog__close el-icon el-icon-close"></div>';
//     document.body.appendChild(qmad_box);  
//     document.querySelector('.qmad_box .close').onclick  = function(){
//       qmad_box.style.display = 'none';
//     };
//   }
// };

