var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);

// list of users by socket id
clients = {};

// ROUTING

app.get('/', function (req, res) {
    res.sendFile(__dirname + '/index.html');
});

// EVENTS

io.on('connection', function(socket) {
	console.log('client connected. socket: ' + socket.id);

    socket.on('join', function(username) {
        console.log('user joining. name: ' + username);
        clients[socket.id] = new ChatClient(username, socket);
    });

	socket.on('disconnect', function() {
		console.log("client disconnected: " + socket.id);
        delete clients[socket.id];
	});

    socket.on('send message', function (message) {
        clients[socket.id].sendMessage(message);
    });
});

// CLIENT OBJECT

function ChatClient(username) {
    this.username = username;

    this.sendMessage = function(message) {
        console.log(this.username + ": " + message);
        io.emit('recieve message', this.username + ": " + message);
    };
};

// STATICS

//app.use(express.static('public'));

// SERVER

var server = http.listen(3000, function() {
    var host = server.address().address;
    var port = server.address().port;

    console.log("rofl lol listening at http://" + host + ":" + port);
});