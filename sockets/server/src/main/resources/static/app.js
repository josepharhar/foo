console.log('creating websocket');
var socket = new WebSocket('ws://127.0.0.1:8080/foo');

socket.onopen = function(event) {
  console.log('socket.onopen');
  socket.send('this is my foo message from js::onopen');
}

socket.send('this is my foo message from js main');
