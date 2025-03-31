// SPDX-License-Identifier: GPL-2.0

#include <oasis/system.h>
#include "esp_log.h"
#include "sdkconfig.h"

#define TAG "oasis_system"

bool oasis_is_qemu(void)
{
#ifdef CONFIG_OASIS_EMULATED_ENV
	ESP_LOGW(TAG, "Detected QEMU via CONFIG_OASIS_EMULATED_ENV");
	return true;
#else
	return false;
#endif
}
