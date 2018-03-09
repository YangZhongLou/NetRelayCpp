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
	ip::tcp::resolver resolver(ioService);
	ip::tcp::resolver::query query("127.0.0.1", "10000");
	ip::tcp::resolver::iterator iter = resolver.resolve(query);

	socket.connect(*iter);

	std::array<char, 4096> bytes;

	auto size = socket.read_some(buffer(bytes));

	std::cout.write(bytes.data(), size);

	return 0;
}