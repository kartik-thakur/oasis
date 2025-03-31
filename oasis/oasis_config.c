#include <string.h>
#include "nvs_flash.h"
#include "nvs.h"
#include <oasis_config.h>

#define OASIS_CONFIG_NAMESPACE   "oasis_cfg"

int oasis_config_load_from_nvs(struct oasis_config *cfg)
{
    nvs_handle_t nvs;
    esp_err_t err;
    size_t len = sizeof(struct oasis_config);

    err = nvs_open(OASIS_CONFIG_NAMESPACE, NVS_READONLY, &nvs);
    if (err != ESP_OK)
        return -1;

    err = nvs_get_blob(nvs, "config", cfg, &len);
    nvs_close(nvs);

    return err == ESP_OK ? 0 : -1;
}

int oasis_config_save_to_nvs(const struct oasis_config *cfg)
{
    nvs_handle_t nvs;
    esp_err_t err;

    err = nvs_open(OASIS_CONFIG_NAMESPACE, NVS_READWRITE, &nvs);
    if (err != ESP_OK)
        return -1;

    err = nvs_set_blob(nvs, "config", cfg, sizeof(struct oasis_config));
    if (err != ESP_OK) {
        nvs_close(nvs);
        return -1;
    }

    err = nvs_commit(nvs);
    nvs_close(nvs);

    return err == ESP_OK ? 0 : -1;
}
