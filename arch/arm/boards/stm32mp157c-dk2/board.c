// SPDX-License-Identifier: GPL-2.0+
#include <common.h>
#include <linux/sizes.h>
#include <init.h>
#include <asm/memory.h>
#include <mach/stm32.h>
#include <mach/bbu.h>

static int dk2_mem_init(void)
{
	if (!of_machine_is_compatible("st,stm32mp157c-dk2"))
		return 0;

	arm_add_mem_device("ram0", STM32_DDR_BASE, SZ_512M);

	return 0;
}
mem_initcall(dk2_mem_init);

static int dk2_postcore_init(void)
{
	if (!of_machine_is_compatible("st,stm32mp157c-dk2"))
		return 0;

	stm32mp_bbu_mmc_register_handler("sd", "/dev/mmc0.ssbl",
					 BBU_HANDLER_FLAG_DEFAULT);

	return 0;
}
postcore_initcall(dk2_postcore_init);
