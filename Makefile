default: debug

debug:
	docker run --rm -ti \
		-v $(shell pwd):$(shell pwd) \
		-w $(shell pwd) \
		atlas/analysisbase:22.2.27

build-docker:
	docker pull atlas/analysisbase:22.2.27
	docker run --rm -ti \
		-v $(shell pwd):$(shell pwd) \
		-w $(shell pwd) \
		atlas/analysisbase:22.2.27 \
		/bin/bash -c 'bash build.sh'

tests-docker:
	docker pull atlas/analysisbase:22.2.27
	docker run --rm -ti \
		-v $(shell pwd):$(shell pwd) \
		-w $(shell pwd) \
		atlas/analysisbase:22.2.27 \
		/bin/bash -c 'bash test_runner.sh'

ci-docker:
	docker pull atlas/analysisbase:22.2.27
	docker run --rm -ti \
		-v $(shell pwd):$(shell pwd) \
		-w $(shell pwd) \
		atlas/analysisbase:22.2.27 \
		/bin/bash -c 'bash tests/ci.sh'

clean-artifacts: $(eval SHELL:=/bin/bash)
	if [ -d build ]; then rm -rf build; fi
	if [ -f core ]; then rm core; fi
