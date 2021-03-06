/*
 * Copyright (c) 2017-2020, AT&T Intellectual Property. All rights reserved.
 * Copyright (c) 2015-2016 by Brocade Communications Systems, Inc.
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * dataplane UT Interface helpers
 */

#ifndef _DP_TEST_LIB_INTF_H_
#define _DP_TEST_LIB_INTF_H_

#include <stdbool.h>
#include <stdint.h>
#include <netinet/in.h> /* conflicts with linux/if_bridge.h */

#include "../vrf.h"
#include "dp_test_pktmbuf_lib.h"

#define DP_TEST_INTF_DEF_SRC_MAC "00:00:a6:00:00:01"

int dp_test_intf_name2index(const char *if_name);
char *dp_test_intf_name2mac_str(const char *if_name);
void dp_test_intf_name2addr(const char *if_name, struct dp_test_addr *addr);
void dp_test_intf_name2addr_str(const char *if_name, int family,
				char *addr_str, int buf_len);

char *dp_test_intf_real(const char *test_name, char *real_name);

vrfid_t _dp_test_translate_vrf_id(vrfid_t vrf_id, const char *file,
			       int line);

#define dp_test_translate_vrf_id(vrf_id) \
	_dp_test_translate_vrf_id(vrf_id, __FILE__, __LINE__)

/* Create / Delete bridge interfaces */
void _dp_test_intf_bridge_create(const char *br_name,
				 const char *file, const char *func,
				 int line);
#define dp_test_intf_bridge_create(br_name) \
	_dp_test_intf_bridge_create(br_name, \
				    __FILE__, __func__, __LINE__)

void _dp_test_intf_bridge_del(const char *br_name,
			      const char *file, const char *func,
			      int line);
#define dp_test_intf_bridge_del(br_name) \
	_dp_test_intf_bridge_del(br_name, \
				 __FILE__, __func__, __LINE__)

void _dp_test_intf_bridge_add_port(const char *br_name, const char *if_name,
				   const char *file, const char *func,
				   int line);
#define dp_test_intf_bridge_add_port(br_name, if_name) \
	_dp_test_intf_bridge_add_port(br_name, if_name, \
				      __FILE__, __func__, __LINE__)

void _dp_test_intf_bridge_remove_port(const char *br_name, const char *if_name,
				      const char *file, const char *func,
				      int line);
#define dp_test_intf_bridge_remove_port(br_name, if_name) \
	_dp_test_intf_bridge_remove_port(br_name, if_name, \
					 __FILE__, __func__, __LINE__)

#endif /* _DP_TEST_LIB_INTF_H_ */
