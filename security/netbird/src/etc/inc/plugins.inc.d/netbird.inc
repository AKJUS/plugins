<?php

/*
 * Copyright (C) 2025 Ralph Moser, PJ Monitoring GmbH
 * Copyright (C) 2025 squared GmbH
 * Copyright (C) 2025 Christopher Linn, BackendMedia IT-Services GmbH
 * Copyright (C) 2025 NetBird GmbH
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

function netbird_enabled()
{
    return !(new \OPNsense\Netbird\Settings())->general->enable->isEmpty();
}

function netbird_services()
{
    $services = [];
    if (!netbird_enabled()) {
        return $services;
    }

    $services[] = [
        'description' => gettext('NetBird'),
        'configd' => [
            'restart' => ['netbird restart'],
            'start' => ['netbird start'],
            'stop' => ['netbird stop'],
        ],
        'name' => 'netbird',
        'pidfile' => '/var/run/netbird.pid',
    ];

    return $services;
}

function netbird_configure()
{
    return [
        'netbird_sync_config' => ['netbird_configure_do']
    ];
}

function netbird_configure_do($verbose = false)
{
    service_log('Sync NetBird config...', $verbose);
    (new \OPNsense\Netbird\Settings())->syncConfig();
    service_log("done.\n", $verbose);
}
