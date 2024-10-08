// Copyright (c) 2021 Habana Labs, Ltd.
// SPDX-License-Identifier: BSD-3-Clause

#include "hccl_ofi_wrapper.h"
#include <cstring>

int ofi_plugin::w_fi_getinfo(int                   version,
                             const char*           node,
                             const char*           service,
                             uint64_t              flags,
                             const struct fi_info* hints,
                             struct fi_info**      info)
{
    return fi_getinfo(version, node, service, flags, hints, info);
}

struct fi_info* ofi_plugin::w_fi_allocinfo()
{
    return fi_allocinfo();
}

struct fi_info* ofi_plugin::w_fi_dupinfo(const struct fi_info* info)
{
    return fi_dupinfo(info);
}

void ofi_plugin::w_fi_freeinfo(struct fi_info* info)
{
    fi_freeinfo(info);
}

const char* ofi_plugin::w_fi_strerror(int err)
{
    return fi_strerror(err);
}

char* ofi_plugin::w_fi_tostr(const void* data, enum fi_type datatype)
{
    return fi_tostr(data, datatype);
}

int ofi_plugin::w_fi_close(fid_t domain)
{
    return fi_close(domain);
}

int ofi_plugin::w_fi_fabric(struct fi_fabric_attr* attr, struct fid_fabric** fabric, void* context)
{
    return fi_fabric(attr, fabric, context);
}

int ofi_plugin::w_fi_domain(struct fid_fabric* fabric, struct fi_info* info, struct fid_domain** domain, void* context)
{
    return fi_domain(fabric, info, domain, context);
}

int ofi_plugin::w_fi_endpoint(struct fid_domain* domain, struct fi_info* info, struct fid_ep** ep, void* context)
{
    return fi_endpoint(domain, info, ep, context);
}

int ofi_plugin::w_fi_cq_open(struct fid_domain* domain, struct fi_cq_attr* attr, struct fid_cq** cq, void* context)
{
    return fi_cq_open(domain, attr, cq, context);
}

int ofi_plugin::w_fi_av_open(struct fid_domain* domain, struct fi_av_attr* attr, struct fid_av** av, void* context)
{
    return fi_av_open(domain, attr, av, context);
}

int ofi_plugin::w_fi_ep_bind(struct fid_ep* ep, struct fid* fid, uint64_t flags)
{
    return fi_ep_bind(ep, fid, flags);
}

int ofi_plugin::w_fi_enable(struct fid_ep* ep)
{
    return fi_enable(ep);
}

int ofi_plugin::w_fi_getname(fid_t fid, void* addr, size_t* addrlen)
{
    return fi_getname(fid, addr, addrlen);
}

int ofi_plugin::w_fi_av_insert(struct fid_av* av,
                               void*          addr,
                               size_t         count,
                               fi_addr_t*     fi_addrs,
                               uint64_t       flags,
                               void*          context)
{
    return fi_av_insert(av, addr, count, fi_addrs, flags, context);
}

int ofi_plugin::w_fi_eq_open(struct fid_fabric* fabric, struct fi_eq_attr* attr, struct fid_eq** eq, void* context)
{
    return fi_eq_open(fabric, attr, eq, context);
}

ssize_t
ofi_plugin::w_fi_eq_sread(struct fid_eq* eq, uint32_t* event, void* buf, size_t len, int timeout, uint64_t flags)
{
    return fi_eq_sread(eq, event, buf, len, timeout, flags);
}

ssize_t ofi_plugin::w_fi_eq_readerr(struct fid_eq* eq, struct fi_eq_err_entry* buf, uint64_t flags)
{
    return fi_eq_readerr(eq, buf, flags);
}

int ofi_plugin::w_fi_passive_ep(struct fid_fabric* fabric, struct fi_info* info, struct fid_pep** pep, void* context)
{
    return fi_passive_ep(fabric, info, pep, context);
}

int ofi_plugin::w_fi_pep_bind(struct fid_pep* pep, struct fid* bfid, uint64_t flags)
{
    return fi_pep_bind(pep, bfid, flags);
}

int ofi_plugin::w_fi_listen(struct fid_pep* pep)
{
    return fi_listen(pep);
}

int ofi_plugin::w_fi_connect(struct fid_ep* ep, const void* addr, const void* param, size_t paramlen)
{
    return fi_connect(ep, addr, param, paramlen);
}

int ofi_plugin::w_fi_accept(struct fid_ep* ep, const void* param, size_t paramlen)
{
    return fi_accept(ep, param, paramlen);
}

ssize_t ofi_plugin::w_fi_tsend(struct fid_ep* ep,
                               const void*    buf,
                               size_t         len,
                               void*          desc,
                               fi_addr_t      dest_addr,
                               uint64_t       tag,
                               void*          context)
{
    return fi_tsend(ep, buf, len, desc, dest_addr, tag, context);
}

ssize_t ofi_plugin::w_fi_trecv(struct fid_ep* ep,
                               void*          buf,
                               size_t         len,
                               void*          desc,
                               fi_addr_t      src_addr,
                               uint64_t       tag,
                               uint64_t       ignore,
                               void*          context)
{
    return fi_trecv(ep, buf, len, desc, src_addr, tag, ignore, context);
}
ssize_t
ofi_plugin::w_fi_send(struct fid_ep* ep, const void* buf, size_t len, void* desc, fi_addr_t dest_addr, void* context)
{
    return fi_send(ep, buf, len, desc, dest_addr, context);
}

ssize_t ofi_plugin::w_fi_recv(struct fid_ep* ep, void* buf, size_t len, void* desc, fi_addr_t src_addr, void* context)
{
    return fi_recv(ep, buf, len, desc, src_addr, context);
}

ssize_t ofi_plugin::w_fi_cq_read(struct fid_cq* cq, void* buf, size_t count)
{
    return fi_cq_read(cq, buf, count);
}

ssize_t ofi_plugin::w_fi_cq_readerr(struct fid_cq* cq, struct fi_cq_err_entry* buf, uint64_t flags)
{
    return fi_cq_readerr(cq, buf, flags);
}

const char* ofi_plugin::w_fi_cq_strerror(struct fid_cq* cq, int prov_errno, const void* err_data, char* buf, size_t len)
{
    return fi_cq_strerror(cq, prov_errno, err_data, buf, len);
}

void* ofi_plugin::w_fi_mr_desc(struct fid_mr* mr)
{
    return fi_mr_desc(mr);
}

int ofi_plugin::w_fi_mr_regattr(struct fid_domain*       domain,
                                const struct fi_mr_attr* attr,
                                uint64_t                 flags,
                                struct fid_mr**          mr)
{
    return fi_mr_regattr(domain, attr, flags, mr);
}

ssize_t ofi_plugin::w_fi_read(struct fid_ep* ep,
                              void*          buf,
                              size_t         len,
                              void*          desc,
                              fi_addr_t      src_addr,
                              uint64_t       addr,
                              uint64_t       key,
                              void*          context)
{
    return fi_read(ep, buf, len, desc, src_addr, addr, key, context);
}

uint64_t ofi_plugin::w_fi_mr_key(struct fid_mr* mr)
{
    return fi_mr_key(mr);
}

uint32_t ofi_plugin::w_fi_version()
{
    return fi_version();
}

extern "C" double get_version()
{
    return OFI_PLUGIN_VERSION;
}

extern "C" ofi_plugin_handle create_ofi_plugin_handle()
{
    return std::unique_ptr<ofi_plugin>(new ofi_plugin());
}
