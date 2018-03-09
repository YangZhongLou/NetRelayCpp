#include <boost/asio/io_service.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <array>
#include <string>
#include <iostream>

using namespace boost::asio;
using namespace boost::asio::ip;

int main()
{
	io_service ioService;
	ip::tcp::socket socket(ioService);
	tcp::endpoint tcpEndpoint{ tcp::v4(), 10000 };
	ip::tcp::acceptor acceptor(ioService, tcpEndpoint);

	acceptor.listen();
	std::cout << "acceptor.listen()" << std::endl;
	acceptor.accept(socket);
	std::cout << "accept" << std::endl;

	ip::tcp::socket new_socket(ioService);
	ip::tcp::resolver resolver(ioService);
	ip::tcp::resolver::query query("www.google.com", "http");
	ip::tcp::resolver::iterator iter = resolver.resolve(query);

	new_socket.connect(*iter);
	std::array<char, 4096> bytes;
	std::cout << "connect" << std::endl;

	std::string r =
      "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
	new_socket.write_some(buffer(r));
	auto size = new_socket.read_some(buffer(bytes));
	std::cout << "read_some" << std::endl;

	socket.write_some(buffer(bytes));
	std::cout << "write_some" << std::endl;

	return 0;
}