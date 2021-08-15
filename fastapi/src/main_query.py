from typing import Optional

from fastapi import FastAPI

app = FastAPI()

fake_items_db = [{"item_name": "Foo"}, {"item_name": "Bar"}, {"item_name": "Baz"}]

@app.get('/items/{item_id}')
async def read_item(item_id: str, q: Optional[int] = None):
  if q:
    return 'q'
  return 'not q'

