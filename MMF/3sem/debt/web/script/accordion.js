function expand(id) {
	var tabs = document.querySelectorAll("div.work-tab"),
	texts = document.querySelectorAll("div.work-tab>div");
	if (texts[id].className == "displayed") {
    	texts[id].className = "hidden";
    	tabs[id].classList.remove("expanded");
  	} 
	else {
    	for (var i = 0; i < texts.length; i++) {
    		if(i == id){
    			texts[id].className = "displayed";
      			tabs[id].classList.add("expanded");
    		}
    		else {
    			texts[i].className = "hidden";
      			tabs[i].classList.remove("expanded");
    		}
    	}
	}
}