import _AnalysisPackage


def test_add():
    assert _AnalysisPackage.add(1, 2) == 3
    assert _AnalysisPackage.add(1, -1) == 0
