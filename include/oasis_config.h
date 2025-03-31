#ifndef _OASIS_CONFIG_H
#define _OASIS_CONFIG_H

#include <stdbool.h>
#include <stdint.h>

#define OASIS_MAX_POTS     6

struct oasis_config {
	float bucket_size_liters;
	char watering_schedule[2][6];	 /* HH:MM */
	uint16_t volume_per_pot_ml[OASIS_MAX_POTS];
	uint8_t active_pots;

	bool enable_rain_skip;
	bool enable_leak_detection;
	bool debug_mode;
};

struct oasis_telemetry {
	float tank_level_percent;
	float battery_voltage;
	uint32_t estimated_days_remaining;

	bool needs_refill;
	bool leak_detected;
	bool rain_detected;

	char last_watered[20];	/* ISO string */
	char last_ota_version[10];
	bool ota_in_progress;
};

struct oasis_flags {
	bool force_sync;
};

int oasis_config_load_from_nvs(struct oasis_config *cfg);
int oasis_config_save_to_nvs(const struct oasis_config *cfg);

#endif /* _OASIS_CONFIG_H */
