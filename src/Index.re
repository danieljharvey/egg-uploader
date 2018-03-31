let initialState: CanvasTypes.state = {
  startCoord: None,
  endCoord: None,
  boxes: [],
};

ReactDOMRe.renderToElementWithId(
  <CanvasReducer
    middlewares=[
      CanvasMiddleware.canvasMiddleware,
      BoxMiddleware.boxMiddleware,
      LogMiddleware.logMiddleware,
    ]
    initial=initialState
  />,
  "app",
);