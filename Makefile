default: debug-image

debug-image:
	docker pull atlas/analysisbase:22.2.27
	docker run --rm -ti \
		-v $(shell pwd):$(shell pwd) \
		-w $(shell pwd) \
		atlas/analysisbase:22.2.27

