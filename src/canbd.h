#ifndef foocanbdfoo
#define foocanbdfoo

#include <inttypes.h>
#include <sys/types.h>

typedef struct CaBlockDevice CaBlockDevice;

enum {
        CA_BLOCK_DEVICE_CLOSED,
        CA_BLOCK_DEVICE_REQUEST,
        CA_BLOCK_DEVICE_POLL,
};

CaBlockDevice *ca_block_device_new(void);
CaBlockDevice *ca_block_device_unref(CaBlockDevice* d);

int ca_block_device_set_size(CaBlockDevice *d, uint64_t size);
int ca_block_device_open(CaBlockDevice *d);

int ca_block_device_step(CaBlockDevice *d);

int ca_block_device_get_request_offset(CaBlockDevice *d, uint64_t *ret);
int ca_block_device_get_request_size(CaBlockDevice *d, uint64_t *ret);

int ca_block_device_put_data(CaBlockDevice *d, uint64_t offset, const void *data, size_t size);

int ca_block_device_poll(CaBlockDevice *d, uint64_t usec);

int ca_block_device_set_path(CaBlockDevice *d, const char *node);
int ca_block_device_get_path(CaBlockDevice *d, const char **ret);

int ca_block_device_test_nbd(const char *name);

#endif
