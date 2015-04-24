# pragma once

# include "rrdb.server.h"
# include <rocksdb/db.h>

namespace dsn {
    namespace apps {
        class rrdb_service_impl : public rrdb_service
        {
        public:
            rrdb_service_impl(::dsn::replication::replica* replica, ::dsn::configuration_ptr& config);

            virtual void on_put(const update_request& update, ::dsn::service::rpc_replier<int>& reply);
            virtual void on_remove(const ::dsn::blob& key, ::dsn::service::rpc_replier<int>& reply);
            virtual void on_merge(const update_request& update, ::dsn::service::rpc_replier<int>& reply);
            virtual void on_get(const ::dsn::blob& key, ::dsn::service::rpc_replier<::dsn::blob>& reply);

            virtual int  open(bool create_new);
            virtual int  close(bool clear_state);
            virtual int  compact(bool force);
            virtual void prepare_learning_request(__out_param blob& learnRequest);
            virtual int  get_learn_state(::dsn::replication::decree start, const blob& learnRequest, __out_param::dsn::replication::learn_state& state);
            virtual int  apply_learn_state(::dsn::replication::learn_state& state);

        private:
            rocksdb::DB* _db;
        };
    }
}
