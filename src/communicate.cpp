#include <vector>
#include <NTL/ZZ_p.h>
#include <NTL/ZZ.h>

#include "constants.hpp"
#include "communicate.hpp"

ZZ_p Share::get_share() {
    return conv<ZZ_p>(ZZFromBytes(share, STORAGE_LEN));
}

vector<ZZ> Share::get_commits() {
    vector<ZZ> res(2);

    for(int i = 0; i < 2; ++i) {
        res[i] = ZZFromBytes(commits[i], STORAGE_LEN);
    }

    return res;
}

vector<uchar> Share::get_cipher() {
    vector<uchar> res(SECRET_LEN);

    for(int i = 0; i < SECRET_LEN; ++i) {
        res[i] = cipher[i];
    }

    return res;
}

void Share::set_share(const ZZ_p &s) {
    BytesFromZZ(share, rep(s), STORAGE_LEN);
}

void Share::set_commits(const vector<ZZ> &c) {
    for(int i = 0; i < 2; ++i) {
        BytesFromZZ(commits[i], c[i], STORAGE_LEN);
    }
}

void Share::set_cipher(const vector<uchar> &c) {
    for(int i = 0; i < SECRET_LEN; ++i) {
        cipher[i] = c[i];
    }
}

ZZ Init::get_q() {
    return ZZFromBytes(q, STORAGE_LEN);
}

ZZ Init::get_p() {
    return ZZFromBytes(g, STORAGE_LEN);
}

void Init::set_q(const ZZ &zq) {
    BytesFromZZ(q, zq, STORAGE_LEN);
}

void Init::set_g(const ZZ &zg) {
    BytesFromZZ(g, zg, STORAGE_LEN);
}
