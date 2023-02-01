
function hello() {
  alert("Hello");
}

// window.onload = function() {  // NUT
//   let btn = document.getElementById("myButton");
//   btn.onclick = hello; 
// };

window.onload = function() {   //Hinh
  var canvas = document.getElementById("sanChoi");
    canvas.width = 800;
    canvas.height = 400;
  var context = canvas.getContext("2d");
  
  // Vẽ vuông
  context.beginPath();
  context.rect(300, 10, 200, 150);
  context.lineWidth = 0;
  context.fillStyle = "none";
  context.fill();
  context.stroke();

  // Vẽ tròn
  context.beginPath()
  context.arc(120, 100, 50 ,0 , 360)
  context.fillStyle="red";
  context.fill()
  context.strokeStyle = "white"
  context.stroke()

  // Vẽ đường
  context.beginPath();
  context.moveTo(600,0);
  context.lineTo(600,400);
  context.lineWidth = "1.5";
  context.strokeStyle = "red";
  context.stroke();

  // Vẽ chữ
  context.beginPath();
  context.font = "42px Arial";
  context.fillStyle = "Black";
  context.strokeStyle = "Yellow";
  context.fillText("Hello",350,200);

  //Vẽ chữ viền
  context.beginPath();
  context.font = "46px Arial";
  context.strokeStyle = "Green";
  context.strokeText("He",348,250);


  
}; 
