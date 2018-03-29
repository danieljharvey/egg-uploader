let initialState: Types.state = {startCoord: None, endCoord: None};

ReactDOMRe.renderToElementWithId(
  <Reducer
    middlewares=[
      LogMiddleware.logMiddleware,
      CanvasMiddleware.canvasMiddleware,
    ]
    initial=initialState
  />,
  "index2",
);