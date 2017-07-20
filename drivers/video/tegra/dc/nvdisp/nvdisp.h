/*
 * drivers/video/tegra/dc/nvdisplay/nvdisp.h
 *
 * Copyright (c) 2014-2017, NVIDIA CORPORATION, All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __DRIVER_VIDEO_TEGRA_DC_NVDISP_H
#define __DRIVER_VIDEO_TEGRA_DC_NVDISP_H

extern struct mutex tegra_nvdisp_lock;
extern struct clk *hubclk;

extern struct list_head nvdisp_imp_settings_queue;

#define NVDISP_TEGRA_POLL_TIMEOUT_MS	50

#define NVDISP_HEAD_ENABLE_DISABLE_TIMEOUT_HZ	(2 * HZ)

struct nvdisp_request_wq {
	wait_queue_head_t	wq;
	atomic_t		nr_pending;
	int			timeout_per_entry;
};

void tegra_nvdisp_set_background_color(struct tegra_dc *dc);
int tegra_nvdisp_assign_win(struct tegra_dc *dc, unsigned idx);
int tegra_nvdisp_detach_win(struct tegra_dc *dc, unsigned idx);
int tegra_nvdisp_get_degamma_config(struct tegra_dc *dc,
	struct tegra_dc_win *win);

int tegra_nvdisp_set_win_csc(struct tegra_dc_win *win,
			struct tegra_dc_nvdisp_win_csc *nvdisp_win_csc);

void tegra_nvdisp_set_common_channel_pending(struct tegra_dc *dc);
void tegra_nvdisp_program_imp_results(struct tegra_dc *dc);

int tegra_nvdisp_program_bandwidth(struct tegra_dc *dc, u32 new_iso_bw,
	u32 new_total_bw, u32 new_emc, u32 new_hubclk, bool before_win_update);
int tegra_nvdisp_negotiate_reserved_bw(struct tegra_dc *dc, u32 new_iso_bw,
	u32 new_total_bw, u32 new_emc, u32 new_hubclk);
void tegra_nvdisp_init_bandwidth(struct tegra_dc *dc);
void tegra_nvdisp_clear_bandwidth(struct tegra_dc *dc);
void tegra_nvdisp_get_max_bw_cfg(struct nvdisp_bandwidth_config *max_cfg);

int __attribute__((weak)) tegra_nvdisp_set_control_t19x(struct tegra_dc *dc);
#endif
