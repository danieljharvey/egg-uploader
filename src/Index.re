let initialState: Types.state = {startCoord: None, endCoord: None, boxes: []};

ReactDOMRe.renderToElementWithId(
  <Reducer
    middlewares=[
      CanvasMiddleware.canvasMiddleware,
      BoxMiddleware.boxMiddleware,
      LogMiddleware.logMiddleware,
    ]
    initial=initialState
  />,
  "index2",
);