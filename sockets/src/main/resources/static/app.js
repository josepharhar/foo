console.log('creating websocket');
var socket = new WebSocket('/foo');

socket.onopen = function(event) {
  console.log('socket.onopen');
  socket.send('this is my foo message from js::onopen');
}

socket.send('this is my foo message from js main');
