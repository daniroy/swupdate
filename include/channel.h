/*
 * Author: Christian Storm
 * Copyright (C) 2016, Siemens AG
 *
 * SPDX-License-Identifier:     GPL-2.0-or-later
 */

#pragma once
#include "channel_op_res.h"

/* SWUpdate Channel Interface.
 *
 * Each channel has to implement this interface.
 * Cf. channel_curl.c for an example implementation basing on curl that
 * is used by server_hawkbit.c implementing support for the
 * [hawkBit](https://projects.eclipse.org/projects/iot.hawkbit) server.
 */
typedef struct channel channel_t;
struct channel {
	channel_op_res_t (*open)(channel_t *this, void *cfg);
	channel_op_res_t (*close)(channel_t *this);
	channel_op_res_t (*get)(channel_t *this, void *data);
	channel_op_res_t (*get_file)(channel_t *this, void *data, int file_handle);
	channel_op_res_t (*put)(channel_t *this, void *data);
	void *priv;
};

channel_t *channel_new(void);
