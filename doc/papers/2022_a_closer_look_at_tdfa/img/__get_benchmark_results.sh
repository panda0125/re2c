#!/usr/bin/env sh

set -e

[ $# -ne 1 ] && { echo "usage: $0 <re2c-root>"; exit 1; }

rootdir="$1"

rm -rf benchmarks && mkdir -p benchmarks/{dfa_aot,dfa_jit}

for variant in dfa_{aot,jit} ; do
    cd benchmarks/"${variant}"
    resultsdir="${rootdir}"/benchmarks/submatch_"${variant}"/results
    results=$(find "${resultsdir}" -name 'results_*.json' | tail -n 1)
    "${resultsdir}"/split_results.sh "${results}"
    cd ../..

    for jsonfile in benchmarks/"${variant}"/*; do
        texfile="$(echo ${jsonfile} | sed -E 's/.*results_[0-9]*_(.*)\.json/benchmark_'${variant}'_\1.tex/')"
        "${resultsdir}/../../json2pgfplot.py" --variant "${variant}" "${jsonfile}" "${texfile}"
    done
done

for flavour in sparse dense; do
    resultsdir="${rootdir}"/benchmarks/submatch_java/results
    cp "$(find ${resultsdir} -name '*_'${flavour}'.tex' | tail -n 1)" "benchmark_java_${flavour}.tex"
done
