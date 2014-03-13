ACLOCAL_AMFLAGS = -I ../m4

bin_SCRIPTS = libpolys-config

SUBDIRS=misc reporter coeffs polys tests

configheaderdir = ${includedir}/singular
nodist_configheader_HEADERS = libpolysconfig.h
DISTCLEANFILES = $(nodist_configheader_HEADERS)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libpolys.pc

DOXYGEN=doxygen # allow replacement from terminal to check different versions easily
DOXYGEN_OUTPUT_DIR_PREFIX := .
DOXYGEN_OUTPUT_DIR_POSTFIX :=/doxygen/
DOXYGEN_OUTPUT_BASEDIR :=$(DOXYGEN_OUTPUT_DIR_PREFIX)/$(DOXYGEN_OUTPUT_DIR_POSTFIX)


DOXYGEN_CONF_DIR :=$(SRCDIR)/doxygen-settings


# works with doxygen 1.7.3-1.8.6. Earlier versions needs different css files.

extended_doxygen:
	export DOXYGEN_INPUT_DIR=$(srcdir); \
	export SRCDIR=$(srcdir); \
	export DOXYGEN_OUTPUT_DIR=$(DOXYGEN_OUTPUT_DIR); \
	export DOXYGEN_OUTPUT_BASEDIR=$(DOXYGEN_OUTPUT_BASEDIR); \
	export DOXYGEN_INCLUDE_DIR=${builddir} \
	export DOXYGEN_BUILD_DIR=${builddir} \
	export DOXYGEN_EXCLUDE_PATTERN=$(DOXYGEN_EXCLUDE_PATTERN); \
	export HAVE_DOT_SETTING=$(HAVE_DOT_SETTING) ; \
	export INHERITMEMBERS=$(INHERITMEMBERS); \
	export CALL_GRAPH_SETTING=$(CALL_GRAPH_SETTING) ; \
	export PROJECT=$(PACKAGE) ; \
	export VERSION=$(PACKAGE_VERSION) ; \
	mkdir -p $(DOXYGEN_OUTPUT_DIR) ; \
	cp ${srcdir}/$(DOXYGEN_CONF_DIR)/doxygen.cfg ${builddir}/doxygen.cfg ; \
	$(DOXYGEN)  -u ./doxygen.cfg ;  \
	$(DOXYGEN) ./doxygen.cfg ; \
	cp ${srcdir}/$(DOXYGEN_CONF_DIR)/styleSheetFile.css $(DOXYGEN_OUTPUT_DIR)/html/doxygen.css ; \
	cp ${srcdir}/$(DOXYGEN_CONF_DIR)/tabs.css $(DOXYGEN_OUTPUT_DIR)/html/tabs.css  ; \
	cp ${srcdir}/$(DOXYGEN_CONF_DIR)/navtree.css $(DOXYGEN_OUTPUT_DIR)/html/navtree.css ; \
	echo "documentation was written to "$(DOXYGEN_OUTPUT_DIR) ;

#doxygen -s  -u ./Doxyconf_copy ; # updates a config file and drops parameter documentation.

# -exporting DOXYGEN_EXCLUDE_PATTERN is required to exclude the documentation folder from parsing if documentation is a subfolder in the source file tree.
# -it is possible to customize the output folder directory by calling 'make tinydocs FACTORY_DOXYGEN_OUTPUT_BASEDIR=$custom_output_directory'



#ifeq ($(INHERITMEMBERS),YES) 
#INHERITED_POSTFIX="_show_inherited" 
#else
#INHERITMEMBERS=NO
#endif



tinydoc:
	$(MAKE) extended_doxygen \
	DOXYGEN_OUTPUT_BASEDIR=${builddir}/$(DOXYGEN_OUTPUT_BASEDIR) \
	DOXYGEN_OUTPUT_DIR=${builddir}/$(DOXYGEN_OUTPUT_BASEDIR)/tiny$(INHERITED_POSTFIX) \
	DOXYGEN_EXCLUDE_PATTERN=*$(OUTPUT_DIR_POSTFIX)* \
	HAVE_DOT_SETTING=NO \
	CALL_GRAPH_SETTING=NO \
	INHERITMEMBERS=$(INHERITMEMBERS) 

smalldoc:
	$(MAKE) extended_doxygen \
	DOXYGEN_OUTPUT_BASEDIR=${builddir}/$(DOXYGEN_OUTPUT_BASEDIR) \
	DOXYGEN_OUTPUT_DIR=${builddir}/$(DOXYGEN_OUTPUT_BASEDIR)/small$(INHERITED_POSTFIX) \
	DOXYGEN_EXCLUDE_PATTERN=*$(DOXYGEN_OUTPUT_DIR_POSTFIX)* \
	HAVE_DOT_SETTING=YES \
	CALL_GRAPH_SETTING=NO \
	INHERITMEMBERS=$(INHERITMEMBERS) 

fulldoc:
	$(MAKE) extended_doxygen \
	DOXYGEN_OUTPUT_BASEDIR=${builddir}/$(DOXYGEN_OUTPUT_BASEDIR) \
	DOXYGEN_OUTPUT_DIR=${builddir}/$(DOXYGEN_OUTPUT_BASEDIR)/full$(INHERITED_POSTFIX) \
	DOXYGEN_EXCLUDE_PATTERN=*$(DOXYGEN_OUTPUT_DIR_POSTFIX)* \
	HAVE_DOT_SETTING=YES \
	CALL_GRAPH_SETTING=YES \
	INHERITMEMBERS=$(INHERITMEMBERS)

