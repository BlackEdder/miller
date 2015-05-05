#include "mapping/mappers.h"
#include "lib/mlrutil.h"
#include "containers/sllv.h"

// ----------------------------------------------------------------
sllv_t* mapper_cat_func(lrec_t* pinrec, context_t* pctx, void* pvstate) {
	if (pinrec != NULL)
		return sllv_single(pinrec);
	else
		return sllv_single(NULL);
}

// ----------------------------------------------------------------
static void mapper_cat_free(void* pvstate) {
}

mapper_t* mapper_cat_alloc() {
	mapper_t* pmapper = mlr_malloc_or_die(sizeof(mapper_t));
	pmapper->pvstate = NULL;
	pmapper->pmapper_process_func = mapper_cat_func;
	pmapper->pmapper_free_func    = mapper_cat_free;
	return pmapper;
}

// ----------------------------------------------------------------
void mapper_cat_usage(char* argv0, char* verb) {
	fprintf(stdout, "Usage: %s %s\n", argv0, verb);
}
mapper_t* mapper_cat_parse_cli(int* pargi, int argc, char** argv) {
	if ((argc - *pargi) < 1) {
		mapper_cat_usage(argv[0], argv[*pargi]);
		return NULL;
	}
	mapper_t* pmapper = mapper_cat_alloc();
	*pargi += 1;
	return pmapper;
}

// ----------------------------------------------------------------
mapper_setup_t mapper_cat_setup = {
	.verb = "cat",
	.pusage_func = mapper_cat_usage,
	.pparse_func = mapper_cat_parse_cli
};