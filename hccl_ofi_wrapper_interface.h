#pragma once
#include <iostream>
#include <sys/socket.h>
#include <set>
#include <map>
#include <memory>
#include <rdma/fabric.h>
#include <rdma/fi_errno.h>
#include <rdma/fi_domain.h>
#include <rdma/fi_endpoint.h>
#include <rdma/fi_cm.h>
#include <rdma/fi_tagged.h>
#include <rdma/fi_rma.h>

namespace hccl
{
class ofi_plugin_interface;
using ofi_plugin_interface_handle = std::unique_ptr<ofi_plugin_interface>;

class ofi_plugin_interface
{
public:
    virtual int             w_fi_getinfo(int                   version,
                                         const char*           node,
                                         const char*           service,
                                         uint64_t              flags,
                                         const struct fi_info* hints,
                                         struct fi_info**      info)                                                 = 0;
    virtual struct fi_info* w_fi_allocinfo()                                                                    = 0;
    virtual void            w_fi_freeinfo(struct fi_info* info)                                                 = 0;
    virtual const char*     w_fi_strerror(int err)                                                              = 0;
    virtual char*           w_fi_tostr(const void* data, enum fi_type datatype)                                 = 0;
    virtual void            w_fi_close(fid_t domain)                                                            = 0;
    virtual int             w_fi_fabric(struct fi_fabric_attr* attr, struct fid_fabric** fabric, void* context) = 0;
    virtual int
                w_fi_domain(struct fid_fabric* fabric, struct fi_info* info, struct fid_domain** domain, void* context) = 0;
    virtual int w_fi_endpoint(struct fid_domain* domain, struct fi_info* info, struct fid_ep** ep, void* context)   = 0;
    virtual int w_fi_cq_open(struct fid_domain* domain, struct fi_cq_attr* attr, struct fid_cq** cq, void* context) = 0;
    virtual int w_fi_av_open(struct fid_domain* domain, struct fi_av_attr* attr, struct fid_av** av, void* context) = 0;
    virtual int w_fi_ep_bind(struct fid_ep* ep, struct fid* fid, uint64_t flags)                                    = 0;
    virtual int w_fi_enable(struct fid_ep* ep)                                                                      = 0;
    virtual int w_fi_getname(fid_t fid, void* addr, size_t* addrlen)                                                = 0;
    virtual int
                    w_fi_av_insert(struct fid_av* av, void* addr, size_t count, fi_addr_t* fi_addrs, uint64_t flags, void* context) = 0;
    virtual ssize_t w_fi_tsend(struct fid_ep* ep,
                               const void*    buf,
                               size_t         len,
                               void*          desc,
                               fi_addr_t      dest_addr,
                               uint64_t       tag,
                               void*          context)                                                       = 0;
    virtual ssize_t w_fi_trecv(struct fid_ep* ep,
                               void*          buf,
                               size_t         len,
                               void*          desc,
                               fi_addr_t      src_addr,
                               uint64_t       tag,
                               uint64_t       ignore,
                               void*          context)                                                       = 0;
    virtual ssize_t w_fi_cq_read(struct fid_cq* cq, void* buf, size_t count)                        = 0;
    virtual ssize_t w_fi_cq_readerr(struct fid_cq* cq, struct fi_cq_err_entry* buf, uint64_t flags) = 0;
    virtual const char*
                  w_fi_cq_strerror(struct fid_cq* cq, int prov_errno, const void* err_data, char* buf, size_t len) = 0;
    virtual void* w_fi_mr_desc(struct fid_mr* mr)                                                                  = 0;
};
}  // namespace hccl
