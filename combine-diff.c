#include "object-store.h"
				    struct lline *newline, int lennew,
	if (newline == NULL)
		return newline;
		for (j = 1, newend = newline; j < lennew + 1; j++) {
				newline = lline->next;
	newend = newline;
		struct strbuf buf = STRBUF_INIT;
		strbuf_addf(&buf, "Subproject commit %s\n", oid_to_hex(oid));
		*size = buf.len;
		blob = strbuf_detach(&buf, NULL);
		fill_filespec(df, oid, 1, mode);
		blob = read_object_file(oid, &type, size);
	int abbrev = opt->flags.full_index ? GIT_SHA1_HEXSZ : DEFAULT_ABBREV;
		abb = find_unique_abbrev(&elem->parent[i].oid,
	abb = find_unique_abbrev(&elem->oid, abbrev);
	if (opt->flags.allow_textconv)
			if (resolve_gitlink_ref(elem->path, "HEAD", &oid) < 0)
			fill_filespec(df, &null_oid, 0, st.st_mode);
				if (convert_to_git(&the_index, elem->path, result, len, &buf, global_conv_flags_eol)) {
static struct combine_diff_path *find_paths_generic(const struct object_id *oid,
	const struct oid_array *parents, struct diff_options *opt)
		diff_tree_oid(&parents->oid[i], oid, "", opt);
	const struct object_id *oid, const struct oid_array *parents,
	const struct object_id **parents_oid;
	ALLOC_ARRAY(parents_oid, nparent);
		parents_oid[i] = &parents->oid[i];
	diff_tree_paths(&paths_head, oid, parents_oid, nparent, &base, opt);
	free(parents_oid);
void diff_tree_combined(const struct object_id *oid,
			const struct oid_array *parents,
	diffopts.flags.recursive = 1;
	diffopts.flags.allow_external = 0;
			opt->flags.follow_renames	||
			(opt->pickaxe_opts & DIFF_PICKAXE_KINDS_MASK)	||
		paths = find_paths_generic(oid, parents, &diffopts);
		paths = find_paths_multitree(oid, parents, &diffopts);
			diff_tree_oid(&parents->oid[0], oid, "", &diffopts);
	struct oid_array parents = OID_ARRAY_INIT;
		oid_array_append(&parents, &parent->item->object.oid);
	diff_tree_combined(&commit->object.oid, &parents, dense, rev);
	oid_array_clear(&parents);