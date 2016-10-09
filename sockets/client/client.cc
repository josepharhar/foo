#include <iostream>
#include <string>
#include <boost/asio.hpp>

//#include "beast/http.hpp"
#include "Beast/include/beast/core/to_string.hpp"
#include "Beast/include/beast/websocket.hpp"

int main(int argc, char** argv) {
  std::cout << "client starting\n";

  //const std::string& host = "ws://127.0.0.1/foo";
  //const std::string& host = "127.0.0.1/foo";
  const std::string& host = "127.0.0.1";
  boost::asio::io_service io_service;
  boost::asio::ip::tcp::resolver resolver{io_service};
  boost::asio::ip::tcp::socket socket{io_service};
  boost::asio::connect(socket,
      resolver.resolve(boost::asio::ip::tcp::resolver::query{host, "8080"}));

  beast::websocket::stream<boost::asio::ip::tcp::socket&> websocket{socket};
  websocket.handshake(host, "/foo");
  websocket.write(boost::asio::buffer("hello from cpp!!!!!!!"));

  websocket.close(beast::websocket::close_code::normal);
  std::cout << "client ending\n";
}
