# JSON files are run through jsonproc, which is a tool that converts JSON data to an output file
# based on an Inja template. https://github.com/pantor/inja

AUTO_GEN_TARGETS += $(DATA_SRC_SUBDIR)/wild_encounters.h
$(DATA_SRC_SUBDIR)/wild_encounters.h: $(DATA_SRC_SUBDIR)/wild_encounters.json $(DATA_SRC_SUBDIR)/wild_encounters.json.txt
	$(JSONPROC) $^ $@

AUTO_GEN_TARGETS += $(DATA_SRC_SUBDIR)/wild_encounters_ruby.h
$(DATA_SRC_SUBDIR)/wild_encounters_ruby.h: $(DATA_SRC_SUBDIR)/wild_encounters_ruby.json $(DATA_SRC_SUBDIR)/wild_encounters.json.txt
	$(JSONPROC) $^ $@

AUTO_GEN_TARGETS += $(DATA_SRC_SUBDIR)/wild_encounters_sapphire.h
$(DATA_SRC_SUBDIR)/wild_encounters_sapphire.h: $(DATA_SRC_SUBDIR)/wild_encounters_sapphire.json $(DATA_SRC_SUBDIR)/wild_encounters.json.txt
	$(JSONPROC) $^ $@

$(C_BUILDDIR)/wild_encounter.o: c_dep += $(DATA_SRC_SUBDIR)/wild_encounters.h $(DATA_SRC_SUBDIR)/wild_encounters_ruby.h $(DATA_SRC_SUBDIR)/wild_encounters_sapphire.h

AUTO_GEN_TARGETS += $(DATA_SRC_SUBDIR)/region_map/region_map_entries.h
$(DATA_SRC_SUBDIR)/region_map/region_map_entries.h: $(DATA_SRC_SUBDIR)/region_map/region_map_sections.json $(DATA_SRC_SUBDIR)/region_map/region_map_sections.json.txt
	$(JSONPROC) $^ $@

$(C_BUILDDIR)/region_map.o: c_dep += $(DATA_SRC_SUBDIR)/region_map/region_map_entries.h
