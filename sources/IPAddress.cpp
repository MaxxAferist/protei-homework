#include "IPAddress.h"


IPAddress::IPAddress(const string &address_string)
{
    ERROR_INFO err_info = set_full_address(address_string);
    if (!err_info)
    {
        log(err_info.info, ERROR);
        return;
    }
}


IPAddress::IPAddress(const vector<uint8_t> &octets)
{
    if (octets.size() != 4)
    {
        log("Invalid octets", ERROR);
        return;
    }
    this->octets = octets;
    this->port = 0;
}


ERROR_INFO IPAddress::get_octets_from_string(const string &octets_string)
{
    if (!is_valid_address(octets_string))
    {
        return ERROR_INFO(ERROR_CODE, "Invalid octets format");
    }
    vector<string> string_octets = split_string(octets_string, ".");
    octets.clear();
    for (auto &elem: string_octets)
    {
        uint8_t octet = static_cast<uint8_t>(stoi(elem, nullptr, 16));
        octets.push_back(octet);
    }
    return ERROR_INFO(S_OK, "Success");
}


ERROR_INFO IPAddress::get_port_from_string(const string &port_string)
{
    if (!isdigit_hex(port_string) || isoverflow_hex(port_string))
    {
        return ERROR_INFO(ERROR_CODE, "Invalid port format");
    }
    int port_int = stoi(port_string, nullptr, 16);
    if (!(0 <= port_int && port_int < 65536))
    {
        return ERROR_INFO(ERROR_CODE, "Port is too big");
    }
    port = static_cast<uint16_t>(port_int);
    return ERROR_INFO(S_OK, "Success");
}


bool IPAddress::is_valid_full_address(const string &full_adress) const
{
    vector<string> address_and_port = split_string(full_adress, ":");
    if (address_and_port.size() != 2)
    {
        return false;
    }
    return true;
}


bool IPAddress::is_valid_address(const string &address) const
{
    vector<string> string_octets = split_string(address, ".");
    if (string_octets.size() != 4)
    {
        return false;
    }
    for (auto &elem: string_octets)
    {
        if (!isdigit_hex(elem) || isoverflow_hex(elem))
        {
            return false;
        }

        int octet = stoi(elem, nullptr, 16);
        if (!(0 <= octet && octet <= 255))
        {
            return false;
        }
    }
    return true;
}


bool IPAddress::is_valid_port(const string &port_string) const
{
    if (!isdigit_hex(port_string) || !isoverflow_hex(port_string))
    {
        return false;
    }
    int port_int = stoi(port_string, nullptr, 16);
    if (!(0 <= port_int && port_int < 65536))
    {
        return false;
    }
    return true;
}


ostream& operator << (ostream& os, const IPAddress& ip_address)
{
    os  << static_cast<int>( ip_address.octets[0] ) << "."
        << static_cast<int>( ip_address.octets[1] ) << "."
        << static_cast<int>( ip_address.octets[2] ) << "."
        << static_cast<int>( ip_address.octets[3] ) << ":"
        << static_cast<int>( ip_address.port );
    return os;
}


ERROR_INFO IPAddress::set_full_address(const string &address_string)
{
    string strip_address = address_string;
    strip(strip_address);
    if (!is_valid_full_address(strip_address))
    {;
        return ERROR_INFO(ERROR_CODE, "Invalid address format");
    }
    vector<string> address_and_port = split_string(strip_address, ":");
    string octets_string = address_and_port[0];
    string port_string = address_and_port[1];

    ERROR_INFO err_info = get_octets_from_string(octets_string);
    if (!err_info)
    {
        return err_info;
    }
    err_info = get_port_from_string(port_string);
    if (!err_info)
    {
        return err_info;
    }
    return ERROR_INFO(S_OK, "Success");
}


ERROR_INFO IPAddress::set_address(const string &new_address)
{
    return get_octets_from_string(new_address);
}


ERROR_INFO IPAddress::set_port(const uint16_t &new_port)
{
    port = new_port;
    return ERROR_INFO(S_OK, "Success");
}