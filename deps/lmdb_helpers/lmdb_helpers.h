#ifndef LMDB_HELPERS_H
#define LMDB_HELPERS_H

#define mdb_fatal(e) { \
        assert(0 != e); \
        fprintf(stderr, "%s:%d - err:%d: %s\n", \
                __FILE__, __LINE__, e, mdb_strerror((e))); \
        exit(1); }

void mdb_db_create(MDB_dbi *dbi, MDB_env *env, const char* db_name);

void mdb_db_env_create(
        MDB_env **env,
	unsigned int flags,
        const char* path,
        int size_mb);
	
void mdb_print_db_stats(MDB_dbi dbi, MDB_env *env);

#endif /* LMDB_HELPERS_H */
