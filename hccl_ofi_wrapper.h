// Copyright (c) 2021 Habana Labs, Ltd.
// SPDX-License-Identifier: BSD-3-Clause


#pragma once
#include <iostream>
#include <sys/socket.h>
#include <set>
#include <map>
#include "hccl_ofi_wrapper_interface.h"

namespace hccl
{
class ofi_plugin;
using ofi_plugin_handle = std::unique_ptr<ofi_plugin>;

class ofi_plugin : public ofi_plugin_interface
{
public:
    int             w_fi_getinfo(int                   version,
                                 const char*           node,
                                 const char*           service,
                                 uint64_t              flags,
                                 const struct fi_info* hints,
                                 struct fi_info**      info);
    struct fi_info* w_fi_allocinfo();
    void            w_fi_freeinfo(struct fi_info* info);
    const char*     w_fi_strerror(int err);
    char*           w_fi_tostr(const void* data, enum fi_type datatype);
    void            w_fi_close(fid_t domain);
    int             w_fi_fabric(struct fi_fabric_attr* attr, struct fid_fabric** fabric, void* context);

    int w_fi_domain(struct fid_fabric* fabric, struct fi_info* info, struct fid_domain** domain, void* context);
    int w_fi_endpoint(struct fid_domain* domain, struct fi_info* info, struct fid_ep** ep, void* context);
    int w_fi_cq_open(struct fid_domain* domain, struct fi_cq_attr* attr, struct fid_cq** cq, void* context);
    int w_fi_av_open(struct fid_domain* domain, struct fi_av_attr* attr, struct fid_av** av, void* context);
    int w_fi_ep_bind(struct fid_ep* ep, struct fid* fid, uint64_t flags);
    int w_fi_enable(struct fid_ep* ep);
    int w_fi_getname(fid_t fid, void* addr, size_t* addrlen);
    int w_fi_av_insert(struct fid_av* av, void* addr, size_t count, fi_addr_t* fi_addrs, uint64_t flags, void* context);
    ssize_t     w_fi_tsend(struct fid_ep* ep,
                           const void*    buf,
                           size_t         len,
                           void*          desc,
                           fi_addr_t      dest_addr,
                           uint64_t       tag,
                           void*          context);
    ssize_t     w_fi_trecv(struct fid_ep* ep,
                           void*          buf,
                           size_t         len,
                           void*          desc,
                           fi_addr_t      src_addr,
                           uint64_t       tag,
                           uint64_t       ignore,
                           void*          context);
    ssize_t     w_fi_cq_read(struct fid_cq* cq, void* buf, size_t count);
    ssize_t     w_fi_cq_readerr(struct fid_cq* cq, struct fi_cq_err_entry* buf, uint64_t flags);
    const char* w_fi_cq_strerror(struct fid_cq* cq, int prov_errno, const void* err_data, char* buf, size_t len);
    void*       w_fi_mr_desc(struct fid_mr* mr);
    int w_fi_mr_regattr(struct fid_domain* domain, const struct fi_mr_attr* attr, uint64_t flags, struct fid_mr** mr);
    uint64_t    w_fi_mr_key(struct fid_mr* mr);
    ssize_t     w_fi_read(struct fid_ep* ep,
                          void*          buf,
                          size_t         len,
                          void*          desc,
                          fi_addr_t      src_addr,
                          uint64_t       addr,
                          uint64_t       key,
                          void*          context);
};
}  // namespace hccl
