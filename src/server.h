#ifndef STATSRELAY_SERVER_H
#define STATSRELAY_SERVER_H

#include "./stats.h"
#include "./tcpserver.h"
#include "./udpserver.h"

#include <stdbool.h>

enum connect_server_collection_state {
	CONNECT_SERVER_COLLECTION_STATE_LISTEN_DOWNSTREAM = 1,
	CONNECT_SERVER_COLLECTION_STATE_UPSTREAM
};

struct server {
	bool enabled;
	stats_server_t *server;
	tcpserver_t *ts;
	udpserver_t *us;
	struct ev_loop *loop;
};

struct server_collection {
	bool initialized;
	char *config_file;
	struct server statsd_server;
	struct server carbon_server;
};

void init_server_collection(struct server_collection *server_collection,
			    const char *filename);

bool connect_server_collection(struct server_collection *server_collection,
			       struct config *config,
			       enum connect_server_collection_state);

void destroy_server_collection(struct server_collection *server_collection);

#endif  // STATSRELAY_SERVER_H
