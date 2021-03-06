/*
 * Copyright (c) 2013 Espressif System.
 *
 *  sdio stub code for RK
 */

//#include <mach/gpio.h>
//#include <mach/iomux.h>

#include <linux/mmc/host.h>

#define ESP8089_DRV_VERSION "1.9"

void sif_platform_rescan_card(unsigned insert)
{
}

void sif_platform_reset_target(void)
{
}

void sif_platform_target_poweroff(void)
{
}

void sif_platform_target_poweron(void)
{
}

void sif_platform_target_speed(int high_speed)
{
}

void sif_platform_check_r1_ready(struct esp_pub *epub)
{
}


#ifdef ESP_ACK_INTERRUPT
extern void sdmmc_ack_interrupt(struct mmc_host *mmc);

void sif_platform_ack_interrupt(struct esp_pub *epub)
{
        struct esp_sdio_ctrl *sctrl = NULL;
        struct sdio_func *func = NULL;

	if (epub == NULL) {
        	ESSERT(epub != NULL);
		return;
	}
        sctrl = (struct esp_sdio_ctrl *)epub->sif;
        func = sctrl->func;
	if (func == NULL) {
        	ESSERT(func != NULL);
		return;
	}

        sdmmc_ack_interrupt(func->card->host);
}
#endif //ESP_ACK_INTERRUPT

late_initcall(esp_sdio_init);
module_exit(esp_sdio_exit);
