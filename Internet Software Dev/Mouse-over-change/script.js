function doMouseOver() {
  document.getElementById("pic").src="gs.jpg";
  document.getElementById("desc").style.color="green";
  document.getElementById("desc").style.fontSize="50px";
  document.getElementById("desc").style.fontFamily="Chiller";
  document.getElementById("desc").innerHTML="This is a german shepherd.";
}
function doMouseOut() {
  document.getElementById("pic").src = "husky.jpg";
  document.getElementById("desc").style.color="blue";
  document.getElementById("desc").style.fontSize="25px";
  document.getElementById("desc").style.fontFamily="Papyrus";
  document.getElementById("desc").innerHTML="This is a husky.";
}