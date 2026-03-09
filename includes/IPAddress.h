#ifndef _IP_ADDRESS_H_
#define _IP_ADDRESS_H_


#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>
#include <memory>

#include "define.h"
#include "some_structures.h"
#include "mytools.h"
#include "mylogger.h"


using namespace std;


class IPAddress {
public:
    IPAddress() = default;
    IPAddress(const string &address_string);
    IPAddress(const vector<uint8_t> &octets);

    ERROR_INFO set_full_address(const string &address_string);

    ERROR_INFO set_address(const string &new_address);
    ERROR_INFO set_port(const uint16_t &new_port);

    friend ostream& operator << (ostream& os, const IPAddress& ip_address);

private:
    vector<uint8_t> octets;
    uint16_t port;

    ERROR_INFO get_octets_from_string(const string &octets_string);
    ERROR_INFO get_port_from_string(const string &port_string);
    bool is_valid_full_address(const string &full_adress) const;
    bool is_valid_address(const string &octets_string) const;
    bool is_valid_port(const string &port_string) const;
};


#endif