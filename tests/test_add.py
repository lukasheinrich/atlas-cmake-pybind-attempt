import _AnalysisPackage
    

def test_add():
    assert _AnalysisPackage.add(1, 2) == 3
    assert _AnalysisPackage.add(1, -1) == 0

def test_column():
    assert _AnalysisPackage.column_maker().tolist() == list(range(10))
