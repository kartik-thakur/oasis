// SPDX-License-Identifier: GPL-2.0

#ifndef __OASIS_SYSTEM_H
#define __OASIS_SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * oasis_is_qemu - Check if the current runtime is under QEMU emulation
 *
 * This function checks the build-time configuration to determine if
 * the firmware is intended to run under QEMU. This is useful to
 * conditionally enable or disable features that behave differently
 * or aren't supported under emulated environments.
 *
 * Return: true if running under QEMU (CONFIG_OASIS_EMULATED_ENV is set), false otherwise.
 */
bool oasis_is_qemu(void);

#ifdef __cplusplus
}
#endif

#endif /* __OASIS_SYSTEM_H */
