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

ci-docker:
	docker pull atlas/analysisbase:22.2.27
	docker run --rm -ti \
		-v $(shell pwd):$(shell pwd) \
		-w $(shell pwd) \
		atlas/analysisbase:22.2.27 \
		/bin/bash -c 'bash tests/ci.sh'
