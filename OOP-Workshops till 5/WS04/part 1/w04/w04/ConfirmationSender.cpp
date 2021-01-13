#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <cstring>
#include "ConfirmationSender.h"

namespace sdds {

    ConfirmationSender::ConfirmationSender()
    {
        c_res = nullptr;
        c_cnt = 0;
    }

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool result = false;
		for (int i = 0; i < c_cnt && result == false; i++) {
			if (&res == c_res[i]) {
				result = true;
			}
		}
		if (result == false) {
			const Reservation** temp = nullptr;
			temp = new const Reservation * [c_cnt + 1];
			for (int i = 0; i < c_cnt; i++) {
				temp[i] = c_res[i];
			}
			temp[c_cnt] = &res;
			c_cnt++;
			delete[] c_res;
			c_res = temp;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
	
        for (int i = 0; i < c_cnt; i++) {
            if (c_res[i] == &res) {
                c_res[i] = nullptr;
            }
        }
        return *this;	
	}

    int ConfirmationSender::size() const
    {
        return c_cnt;
    }


    ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)
    {
        if (src.c_res != nullptr)
        {
            swap(c_res, src.c_res);
            c_cnt = src.c_cnt;
            src.c_cnt = 0;
            src.c_res = nullptr;
        }
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender& src)
    {
        if (src.c_res != nullptr)
        {
            delete[] c_res;
            this->c_res = new const Reservation * [src.c_cnt + 1];
            for (int i = 0; i < src.c_cnt; i++)
            {
                this->c_res[i] = src.c_res[i];
            }
            c_cnt = src.c_cnt;
        }
    }

    ostream& operator<<(std::ostream& os, const ConfirmationSender& res) {
        os << "--------------------------" << std::endl;
        os << "Confirmations to Send" << std::endl;
        os << "--------------------------" << std::endl;

        if (res.c_res == nullptr) {
            os << "The object is empty!" << std::endl;
            os << "--------------------------" << std::endl;
        }
        else {
            for (int i = 0; i < res.c_cnt; i++) {
                if (res.c_res[i] != nullptr) {
                    os << *res.c_res[i];
                }
            }

            os << "--------------------------" << std::endl;

        }
        return  os;
    }
        ConfirmationSender::~ConfirmationSender()
    {
        delete[] c_res;
        c_res = nullptr;
    }
}